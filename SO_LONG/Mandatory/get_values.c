/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:10:52 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/08 15:46:40 by ababdelo         ###   ########.fr       */
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

void	get_collectible_pos(t_data *data, int i, int j, int k)
{
	data->collc_pos = malloc(sizeof(t_pos) * data->collect_cntr);
	if (!data->collc_pos)
		print_msg("Error\nfailed allocating collec_info struct\n", 1);
	while (++i < (data->collect_cntr + 1))
	{
		data->collc_pos[i].x_pos = 0;
		data->collc_pos[i].y_pos = 0;
	}
	i = -1;
	k = -1;
	while (data->dup_buff[++i])
	{
		j = -1;
		while (data->dup_buff[i][++j])
		{
			if (data->dup_buff[i][j] == 'C')
			{
				++k;
				data->collc_pos[k].x_pos = i;
				data->collc_pos[k].y_pos = j;
			}
		}
	}
}

void	get_exit_pos(t_data *data, int i, int j)
{
	data->exit_pos.x_pos = 0;
	data->exit_pos.y_pos = 0;
	while (data->dup_buff[++i])
	{
		j = -1;
		while (data->dup_buff[i][++j])
		{
			if (data->dup_buff[i][j] == 'E')
			{
				data->exit_pos.x_pos = j;
				data->exit_pos.y_pos = i;
			}
		}
	}
}

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
			(data->exit_pos.x_pos * 50) + 2, (data->exit_pos.y_pos * 50) + 2);
	}
	return (0);
}
