/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:42:33 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/18 21:21:03 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PIPEX.h"

void	forkproc(t_data *data)
{
	int	pid[2];
	int index = -1;

	while ( ++index < 2)
	{
		pid[index] = fork();
		if (pid[index] == 0)
		{
			dup2(data->cmd[index].infile,0);
			dup2(data->cmd[index].outfile,1);
			//fprintf(stderr, "process[%d]\n", index);
			closefd(data);
			choose_action(data, index);
			exit(1);
		}
	}
	closefd(data);
	index = -1;
	while ( ++index < 2)
	{
		// fprintf(stderr,"%d done\n",index);
		waitpid(pid[index],NULL, 2);
	}
}

void	choose_action(t_data *data, int index)
{
	int	cntr;
	
	cntr = -1;
	if (data->argv[index+2][0] != '/')
		while (++cntr < data->cntr_)		
			execve(data->cmd[index].newpaths[cntr], data->cmd[index].args,data->envir);
	else
		execve(data->cmd[index].cmd, data->cmd[index].args,data->envir);
}

void	closefd(t_data *data)
{
	if(close(data->cmd[0].infile) == -1)
		printf("1\n");
	if(close(data->cmd[0].outfile) == -1)
		printf("2\n");
	if(close(data->cmd[1].infile) == -1)
		printf("3\n");
	if(close(data->cmd[1].outfile) == -1)
		printf("4\n");
}
