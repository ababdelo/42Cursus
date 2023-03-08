/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items_reachability.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:14:59 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/08 15:50:16 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

void	floodfill(int x_pos, int y_pos, t_data *data, char c)
{
	if ((x_pos > data->height || x_pos < 0)
		|| (y_pos > data->width || y_pos < 0))
		return ;
	if (c == 'C')
	{
		if (data->dup_buff[x_pos][y_pos] != 'P'
			&& data->dup_buff[x_pos][y_pos] != 'C'
			&& data->dup_buff[x_pos][y_pos] != '0')
			return ;
		data->dup_buff[x_pos][y_pos] = '+';
	}
	if (c == 'E')
	{
		if (data->dup_buff[x_pos][y_pos] != '+'
			&& data->dup_buff[x_pos][y_pos] != 'E'
			&& data->dup_buff[x_pos][y_pos] != '0')
			return ;
		data->dup_buff[x_pos][y_pos] = '-';
	}
	floodfill(x_pos + 1, y_pos, data, c);
	floodfill(x_pos, y_pos + 1, data, c);
	floodfill(x_pos - 1, y_pos, data, c);
	floodfill(x_pos, y_pos - 1, data, c);
}

void	check_map_path(t_data *data, int i, int j)
{
	while (data->dup_buff[++i])
	{
		j = -1;
		while (data->dup_buff[i][++j])
		{
			if (data->dup_buff[i][j] == 'P')
			{				
				data->player_virtual_pos[0] = i;
				data->player_virtual_pos[1] = j;
			}
		}
	}
	check_collectibles_reachability(data, -1);
	check_exit_reachability(data, -1);
}

void	check_collectibles_reachability(t_data *data, int i)
{
	int	j;

	floodfill(data->player_virtual_pos[0],
		data->player_virtual_pos[1], data, 'C');
	while (data->dup_buff[++i])
	{
		j = -1;
		while (data->dup_buff[i][++j])
		{
			if (data->dup_buff[i][j] == 'C')
			{
				print_msg_2_shell("Error\n");
				print_msg("Collec_ are not all reachable for the player\n", 1);
			}
		}
	}
}

void	check_exit_reachability(t_data *data, int i)
{
	int	j;

	floodfill(data->player_virtual_pos[0],
		data->player_virtual_pos[1], data, 'E');
	while (data->dup_buff[++i])
	{
		j = -1;
		while (data->dup_buff[i][++j])
		{
			if (data->dup_buff[i][j] == 'E')
				print_msg("Error\nExit is not reachable for the player\n", 1);
		}
	}
}
