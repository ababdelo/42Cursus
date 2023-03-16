/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:56:31 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/07 11:02:07 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

void	put_mouvement_2_win(t_data *data, int x, int y)
{
	char	*str;

	str = ft_itoa(data->moves_cntr);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall_, 0, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall_, 50, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall_, 100, 0);
	mlx_string_put(data->mlx, data->mlx_win, x, y, 16777215, "Moves :");
	mlx_string_put(data->mlx, data->mlx_win, x + 75, y, 16777215, str);
	data->moves_cntr++;
	free(str);
}
