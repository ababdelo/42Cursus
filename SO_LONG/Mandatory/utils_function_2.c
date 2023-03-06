/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:58:34 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/06 11:59:01 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

int	ft_strlen(char *str, char c)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index] != c && str[index])
		index++;
	return (index);
}

void	print_msg(char *err, int ret)
{
	write(2, err, ft_strlen(err, '\0'));
	exit(ret);
}

int	exit_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	print_msg("exit successfully !\n", 0);
	return (0);
}
