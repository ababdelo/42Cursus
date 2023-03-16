/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:42:33 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/16 17:40:16 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

void	forkproc(t_data *data)
{
	int	cntr;
	int exit_status = 0;
	int	pid[2];
	int index = -1;

	cntr = -1;
	while ( ++index < 2)
	{
		pid[index] = fork();
		if (pid[index] == 0)
		{
			dup2(data->cmd[index].infile,0);
			dup2(data->cmd[index].outfile,1);
			closefd(data);
			
			if (data->argv[2][0] != '/')
				while (++cntr < data->cntr_)
					execve(data->cmd[index].newpaths[cntr], data->cmd[index].args,data->envir);
			else
				execve(data->cmd[index].cmd, data->cmd[index].args,data->envir);
			exit(0);
		}
	}
	index = -1;
	while ( ++index < 2)
		waitpid(pid[index],&exit_status, 1);
	closefd(data);
}

// void	to_do(t_data *data)
// {
	
// }

void	closefd(t_data *data)
{
	close(data->cmd[0].infile);
	close(data->cmd[0].outfile);
	close(data->cmd[1].infile);
	close(data->cmd[1].outfile);
}
