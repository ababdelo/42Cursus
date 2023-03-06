/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:11:51 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/06 22:40:00 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

void	move_forward(t_data *data)
{
	int		old_x_pos;
	int		old_y_pos;
	int		new_y_pos;

	check_game_goal(data, data->player_pos - data->width - 1);
	if (data->buff[data->player_pos - data->width - 1] == '0'
		|| data->buff[data->player_pos - data->width - 1] == 'C')
	{
		if (data->buff[data->player_pos - data->width - 1] == 'C')
			data->eated_collec_cntr++;
		data->buff[data->player_pos] = '0';
		data->buff[data->player_pos - data->width - 1] = 'P';
		old_y_pos = (data->player_pos / (data->width + 1)) * data->block_size;
		old_x_pos = (data->player_pos % (data->width + 1)) * data->block_size;
		new_y_pos = old_y_pos - data->block_size;
		get_player_pos(data, old_x_pos, new_y_pos);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dirt_,
			old_x_pos, old_y_pos);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->right_face,
			old_x_pos + 2, new_y_pos + 2);
		data->player_pos = data->player_pos - data->width - 1;
		put_mouvement_2_win(data, 10, 10);
	}
}

void	move_right(t_data *data)
{
	int		old_x_pos;
	int		old_y_pos;
	int		new_x_pos;

	check_game_goal(data, data->player_pos + 1);
	if (data->buff[data->player_pos + 1] == '0'
		|| data->buff[data->player_pos + 1] == 'C')
	{
		if (data->buff[data->player_pos + 1] == 'C')
			data->eated_collec_cntr++;
		data->buff[data->player_pos] = '0';
		data->buff[data->player_pos + 1] = 'P';
		old_y_pos = (data->player_pos / (data->width + 1)) * data->block_size;
		old_x_pos = (data->player_pos % (data->width + 1)) * data->block_size;
		new_x_pos = old_x_pos + data->block_size;
		get_player_pos(data, new_x_pos, old_y_pos);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dirt_,
			old_x_pos, old_y_pos);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->right_face,
			new_x_pos + 2, old_y_pos + 2);
		data->player_pos = data->player_pos + 1;
		put_mouvement_2_win(data, 10, 10);
	}
}

void	move_left(t_data *data)
{
	int		old_x_pos;
	int		old_y_pos;
	int		new_x_pos;

	check_game_goal(data, data->player_pos - 1);
	if (data->buff[data->player_pos - 1] == '0'
		|| data->buff[data->player_pos - 1] == 'C')
	{
		if (data->buff[data->player_pos - 1] == 'C')
			data->eated_collec_cntr++;
		data->buff[data->player_pos] = '0';
		data->buff[data->player_pos - 1] = 'P';
		old_y_pos = (data->player_pos / (data->width + 1)) * data->block_size;
		old_x_pos = (data->player_pos % (data->width + 1)) * data->block_size;
		new_x_pos = old_x_pos - data->block_size;
		get_player_pos(data, new_x_pos, old_y_pos);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dirt_,
			old_x_pos, old_y_pos);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->right_face,
			new_x_pos + 2, old_y_pos + 2);
		data->player_pos = data->player_pos - 1;
		put_mouvement_2_win(data, 10, 10);
	}
}

void	move_backward(t_data *data)
{
	int		old_x_pos;
	int		old_y_pos;
	int		new_y_pos;

	check_game_goal(data, data->player_pos + data->width + 1);
	if (data->buff[data->player_pos + data->width + 1] == '0'
		|| data->buff[data->player_pos + data->width + 1] == 'C')
	{
		if (data->buff[data->player_pos + data->width + 1] == 'C')
			data->eated_collec_cntr++;
		data->buff[data->player_pos] = '0';
		data->buff[data->player_pos + data->width + 1] = 'P';
		old_y_pos = (data->player_pos / (data->width + 1)) * data->block_size;
		old_x_pos = (data->player_pos % (data->width + 1)) * data->block_size;
		new_y_pos = old_y_pos + data->block_size;
		get_player_pos(data, old_x_pos, new_y_pos);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dirt_,
			old_x_pos, old_y_pos);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->right_face,
			old_x_pos + 2, new_y_pos + 2);
		data->player_pos = data->player_pos + data->width + 1;
		put_mouvement_2_win(data, 10, 10);
	}
}
