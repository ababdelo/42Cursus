/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:43:09 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/18 21:21:21 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PIPEX.h"

void	initialize(t_data *data, char **av, char **ev)
{
	data->argv = av;
	data->envir = ev;
	data->paths = NULL;
	data->infile_ = 0;
	data->outfile_ = 0;
	data->cmd = malloc (sizeof(t_cmd) * 2);
	data->cmd[0].newpaths = NULL;
	data->cmd[1].newpaths = NULL;
	data->cmd[0].args = NULL;
	data->cmd[0].cmd = NULL;
	data->cmd[0].infile = 0;
	data->cmd[0].outfile = 0;
	data->cmd[1].args = NULL;
	data->cmd[1].cmd = NULL;
	data->cmd[1].infile = 0;
	data->cmd[1].outfile = 0;
	data->cntr_ = 0;
}
