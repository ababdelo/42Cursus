/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:51:30 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/08 15:55:31 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

int	exit_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	print_msg("exit successfully !\n", 0);
	return (0);
}

void	duplicate_buff(t_data *data, int index, int x, int y)
{
	data->dup_buff = malloc(sizeof (char *) * (data->height + 1));
	if (!data->dup_buff)
		print_msg("Error\nallocating dup_buff failed\n", 1);
	data->dup_buff[data->height] = NULL;
	while (index < data->height)
	{
		data->dup_buff[index] = malloc(sizeof(char) * data->width + 1);
		if (!data->dup_buff[index])
			print_msg("Error\nallocating dup_buff index failed\n", 1);
		index++;
	}
	index = -1;
	while (data->buff[++index])
	{
		if (data->buff[index] == '\n')
		{
			data->dup_buff[x++][y] = '\0';
			y = 0;
		}
		else
			data->dup_buff[x][y++] = data->buff[index];
	}
	data->dup_buff[x][y] = '\0';
}

void	chk_p_c_e(t_data *data, int x, int y, int index)
{
	if (data->buff[index] == 'P')
	{
		data->player_pos = index;
		get_player_pos(data, x, y);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->dirt_, x, y);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->right_face, x + 2, y + 2);
	}
	else if (data->buff[index] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->dirt_, x, y);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->collect_, x + 7, y + 7);
	}
	else if (data->buff[index] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->dirt_, x, y);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->empty_portal_, x + 2, y + 2);
	}
}

void	chk_0_1_x(t_data *data, int x, int y, int index)
{
	if (data->buff[index] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->wall_, x, y);
	else if (data->buff[index] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->dirt_, x, y);
	else if (data->buff[index] == 'X')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->dirt_, x, y);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->enemy_, x + 5, y + 5);
	}
}

void	print2win(t_data *data, int x, int y, int index)
{
	while (data->buff[++index])
	{
		if (data->buff[index] == '\n')
		{
			y += data->block_size;
			x = 0;
		}
		chk_0_1_x(data, x, y, index);
		chk_p_c_e(data, x, y, index);
		if (data->buff[index] != '\n')
			x += data->block_size;
	}
}
