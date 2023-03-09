/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:42:29 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/09 17:53:24 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

void	check_file_accessebility(t_data *data)
{
	data->infile_ = open(data->argv[1], O_RDONLY);
	data->outfile_ = open(data->argv[4], O_WRONLY | 0644);
	if (data->infile_ == -1)
		print_msg("Error openning infile\n", 1);
	if (data->outfile_ == -1)
		print_msg("Error openning outfile\n", 1);
}

