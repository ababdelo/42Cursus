/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:42:33 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/25 16:39:15 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PIPEX.h"

void	forkproc(t_data *data)
{
	int	pid[2];
	int	index;

	index = -1;
	while (++index < 2)
	{
		if (data->cmd[index].infile != -1)
			pid[index] = fork();
		if (pid[index] == 0)
		{
			dup2(data->cmd[index].infile, 0);
			dup2(data->cmd[index].outfile, 1);
			closefd(data);
			choose_action(data, index, -1);
			exit(1);
		}
	}
	closefd(data);
	index = -1;
	while (++index < 2)
		waitpid(pid[index], NULL, 2);
}

void	choose_action(t_data *data, int index, int cntr)
{
	int	ret;

	if (data->argv[index + 2][0] != '/')
	{
		while (++cntr < data->cntr_)
		{
			ret = execve(data->cmd[index].newpaths[cntr],
					data->cmd[index].args, data->envir);
		}
	}
	else
	{
		ret = execve(data->cmd[index].cmd,
				data->cmd[index].args, data->envir);
	}
	if (ret == -1)
	{
		if (index == 0)
			print_msg("Failed execute the first command \n", 1);
		if (index == 1)
			print_msg("Failed execute the second command \n", 1);
	}
}

void	closefd(t_data *data)
{
	if (data->cmd[0].infile != -1)
		close(data->cmd[0].infile);
	close(data->cmd[0].outfile);
	close(data->cmd[1].infile);
	close(data->cmd[1].outfile);
}
