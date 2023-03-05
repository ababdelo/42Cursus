/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:14:44 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/05 14:26:04 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

int	animate_player(t_data *data)
{
	static int	i = -1;
	static int	frame = 0;

	printf("%d %d \n", data->player_virtual_pos[0], data->player_virtual_pos[1]);
	if (++frame < 3500)
		return (0);
	if (++i == 0)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dirt_,
			data->player_virtual_pos[1], data->player_virtual_pos[0]);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->right_face,
			data->player_virtual_pos[1] + 2, data->player_virtual_pos[0] + 2);
	}
	else if (i == 1)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dirt_,
			data->player_virtual_pos[1], data->player_virtual_pos[0]);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->left_face,
			data->player_virtual_pos[1] + 2, data->player_virtual_pos[0] + 2);
	}
	else
		i = -1;
	frame = 0;
	return (0);
}
