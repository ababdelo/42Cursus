/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:42:29 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/19 20:28:46 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PIPEX.h"

void	check_file_accessebility(t_data *data)
{
	data->infile_ = open(data->argv[1], O_RDONLY);
	if (data->infile_ == -1)
		print_msg("Error openning infile\n", 0);
	data->outfile_ = open(data->argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (data->outfile_ == -1)
		print_msg("Error openning outfile\n", 1);
}

void	check_args(t_data *data)
{
	if (data->argv[2][0] != '\0' && data->argv[3][0] != '\0')
	{
		get_env_path(data);
		fill_cmd_struct(data);
	}
	else
		print_msg("[Error]\n it shouldn't be an empty parameter\n", 1);
}
