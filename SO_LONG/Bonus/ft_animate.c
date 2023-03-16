/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:45:20 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/07 13:19:29 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

void	move_collect_up(t_data *data, int j, int index)
{
	if (data->buff[j] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dirt_,
			data->collc_pos[index].x_winpos,
			data->collc_pos[index].y_winpos);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->collect_,
			data->collc_pos[index].x_winpos + 7,
			data->collc_pos[index].y_winpos + 7);
	}
}

void	move_collect_down(t_data *data, int j, int index)
{
	if (data->buff[j] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dirt_,
			data->collc_pos[index].x_winpos,
			data->collc_pos[index].y_winpos);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->collect_,
			data->collc_pos[index].x_winpos + 7,
			data->collc_pos[index].y_winpos);
	}
}

void	move_enemy_right(t_data *data, int j, int index)
{
	if (data->buff[j] == 'X')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dirt_,
			data->enemy_pos[index].x_winpos,
			data->enemy_pos[index].y_winpos);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->enemy_,
			data->enemy_pos[index].x_winpos + 7,
			data->enemy_pos[index].y_winpos + 5);
	}
}

void	move_enemy_left(t_data *data, int j, int index)
{
	if (data->buff[j] == 'X')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dirt_,
			data->enemy_pos[index].x_winpos,
			data->enemy_pos[index].y_winpos);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->enemy_,
			data->enemy_pos[index].x_winpos + 2,
			data->enemy_pos[index].y_winpos + 4);
	}
}
