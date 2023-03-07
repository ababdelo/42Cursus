/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:14:44 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/07 12:45:52 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

int	animate(t_data *data)
{
	int	index;

	index = -1;
	animate_player(data, data->plr_xpos, data->plr_ypos);
	animate_collectibles(data, index);
	animate_enemies(data, index);
	return (0);
}

void	animate_player(t_data *data, int x, int y)
{
	static int	i = -1;
	static int	frame = 0;

	if (++frame < 2500)
		return ;
	if (++i == 0)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dirt_,
			x, y);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->right_face,
			x + 2, y + 2);
	}
	else if (i == 1)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dirt_,
			x, y);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->left_face,
			x + 2, y + 2);
	}
	else
		i = -1;
	frame = 0;
}

void	animate_collectibles(t_data *data, int index)
{
	static int	i = -1;
	static int	frame = 0;
	int			j;

	if (++frame < 2500)
		return ;
	while (++index < data->collect_cntr)
	{
		j = ((data->width + 1) * (data->collc_pos[index].x_bufferpos)
				+ data->collc_pos[index].y_bufferpos);
		if (++i == 0)
			move_collect_up(data, j, index);
		else if (i == 1)
			move_collect_down(data, j, index);
		else
			i = -1;
	}
	frame = 0;
}

void	animate_enemies(t_data *data, int index)
{
	static int	i = -1;
	static int	frame = 0;
	int			j;

	if (++frame < 2500)
		return ;
	while (++index < data->enemy_cntr)
	{
		j = ((data->width + 1) * (data->enemy_pos[index].x_bufferpos)
				+ data->enemy_pos[index].y_bufferpos);
		if (++i == 0)
			move_enemy_left(data, j, index);
		else if (i == 1)
			move_enemy_right(data, j, index);
		else
			i = -1;
	}
	frame = 0;
}
