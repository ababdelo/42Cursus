/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:57:58 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/19 00:13:33 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PIPEX.h"

void	fill_cmd_struct(t_data *data)
{
	int	ret;
	int	filesdes[2];

	data->cmd[0].args = ft_split(data->argv[2], ' ');
	data->cmd[1].args = ft_split(data->argv[3], ' ');
	data->cmd[0].cmd = data->cmd[0].args[0];
	data->cmd[1].cmd = data->cmd[1].args[0];
	ret = pipe(filesdes);
	if (ret == -1)
		print_msg("\t[Error]\n couldn't create descriptor pipe\n", 1);
	data->cmd[0].infile = data->infile_;
	data->cmd[0].outfile = filesdes[1];
	data->cmd[1].infile = filesdes[0];
	data->cmd[1].outfile = data->outfile_;
}

void	get_env_path(t_data *data)
{
	int		index;
	char	*path_;

	index = -1;
	while (data->envir[++index] != NULL)
	{
		path_ = ft_strnstr(data->envir[index], "PATH=", 5);
		if (path_ != NULL)
			break ;
	}
	data->paths = ft_split(path_, ':');
}

void	add_cmdname_2_path(t_data *data)
{
	int	index;

	index = -1;
	while (data->paths[++index] != NULL)
		data->cntr_++;
	data->cmd[0].newpaths = malloc(sizeof(char *) * data->cntr_);
	if (!data->cmd[0].newpaths)
		print_msg("\t[Error]\n Couldn't allocate for cmdpath[0]\n", 1);
	data->cmd[1].newpaths = malloc(sizeof(char *) * data->cntr_);
	if (!data->cmd[1].newpaths)
		print_msg("\t[Error]\n Couldn't allocate for cmdpath[1]\n", 1);
	index = -1;
	while (data->paths[++index] != NULL)
	{
		data->cmd[0].newpaths[index] = ft_strjoin(data->paths[index],
				data->cmd[0].cmd);
		data->cmd[1].newpaths[index] = ft_strjoin(data->paths[index],
				data->cmd[1].cmd);
	}
}
