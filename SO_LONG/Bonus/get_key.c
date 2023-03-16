/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:21:53 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/07 13:22:24 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

int	get_key_pressed(int keycode, t_data *data)
{
	if (keycode == EXIT)
		exit_win(data);
	else if (keycode == UP || keycode == AR_UP)
		move_forward(data);
	else if (keycode == DOWN || keycode == AR_DOWN)
		move_backward(data);
	else if (keycode == RIGHT || keycode == AR_RIGHT)
		move_right(data);
	else if (keycode == LEFT || keycode == AR_LEFT)
		move_left(data);
	else if (keycode == 17)
		exit(0);
	if (data->eated_collec_cntr == data->collect_cntr)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->filled_portal_,
			(data->exit_pos.x_winpos) + 2, (data->exit_pos.y_winpos) + 2);
	}
	return (0);
}
