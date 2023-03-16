/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:10:52 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/08 15:54:09 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

void	get_map_size(t_data *data, int i)
{
	while (data->buff[++i] && data->buff[i] != '\n')
		data->width += 1;
	i = -1;
	while (data->buff[++i])
		if (data->buff[i] == '\n')
			data->height += 1;
	if (data->buff[i] == '\0')
		data->height += 1;
	if (data->width * 50 > 2560 || data->height * 50 > 1440)
	{
		print_msg_2_shell("Error\n");
		print_msg("program window is too large than ' 2560 X 1440 '!\n", 1);
	}
}

void	get_player_pos(t_data *data, int x_pos, int y_pos)
{
	data->plr_xpos = x_pos;
	data->plr_ypos = y_pos;
}

void	get_collectible_pos(t_data *data, int i, int j, int k)
{
	initialize_collec(data, i);
	while (data->dup_buff[++i])
	{
		j = -1;
		while (data->dup_buff[i][++j])
		{
			if (data->dup_buff[i][j] == 'C')
			{
				++k;
				data->collc_pos[k].x_bufferpos = i;
				data->collc_pos[k].y_bufferpos = j;
				data->collc_pos[k].x_winpos = j * 50;
				data->collc_pos[k].y_winpos = i * 50;
			}
		}
	}
}

void	get_exit_pos(t_data *data, int i, int j)
{
	data->exit_pos.x_bufferpos = 0;
	data->exit_pos.y_bufferpos = 0;
	data->exit_pos.x_winpos = 0;
	data->exit_pos.y_winpos = 0;
	while (data->dup_buff[++i])
	{
		j = -1;
		while (data->dup_buff[i][++j])
		{
			if (data->dup_buff[i][j] == 'E')
			{
				data->exit_pos.x_bufferpos = i;
				data->exit_pos.y_bufferpos = j;
				data->exit_pos.x_winpos = j * 50;
				data->exit_pos.y_winpos = i * 50;
			}
		}
	}
}

void	get_enemy_pos(t_data *data, int i, int j, int k)
{
	initialize_enemy(data, 0);
	while (data->dup_buff[++i])
	{
		j = -1;
		while (data->dup_buff[i][++j])
		{
			if (data->dup_buff[i][j] == 'X')
			{
				++k;
				data->enemy_pos[k].x_bufferpos = i;
				data->enemy_pos[k].y_bufferpos = j;
				data->enemy_pos[k].x_winpos = j * 50;
				data->enemy_pos[k].y_winpos = i * 50;
			}
		}
	}
}
