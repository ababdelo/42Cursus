/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:14:44 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/05 23:21:18 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

int	animate(t_data *data)
{
	animate_player(data);
	animate_collectibles(data);

	return(0);
}

void	animate_player(t_data *data)
{
	static int	i = -1;
	static int	frame = 0;

	if (++frame < 2500)
		return ;
	if (++i == 0)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dirt_,
			data->plr_xpos, data->plr_ypos);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->right_face,
			data->plr_xpos + 2, data->plr_ypos + 2);
	}
	else if (i == 1)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dirt_,
			data->plr_xpos, data->plr_ypos);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->left_face,
			data->plr_xpos + 2, data->plr_ypos + 2);
	}
	else
		i = -1;
	frame = 0;
}

void	animate_collectibles(t_data *data)
{
	static int	i = -1;
	static int	frame = 0;
	int	index;
	int j;

	if (++frame < 2000)
		return ;
	index = -1;
	while (++index < data->collect_cntr)
	{
		j = ((data->width + 1) * (data->collc_pos[index].x_bufferpos) + data->collc_pos[index].y_bufferpos);
		if (++i == 0)
		{
			if (data->buff[j]== 'C')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->dirt_,
					data->collc_pos[index].x_winpos, data->collc_pos[index].y_winpos);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->collect_,
					data->collc_pos[index].x_winpos + 7, data->collc_pos[index].y_winpos + 8);
			}
		}
		else if (i == 1)
		{
			if (data->buff[j]== 'C')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->dirt_,
					data->collc_pos[index].x_winpos, data->collc_pos[index].y_winpos);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->collect_,
					data->collc_pos[index].x_winpos + 7, data->collc_pos[index].y_winpos);
			}
		}
		else
			i = -1;
	}
	frame = 0;
}
