/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items_reachability.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:14:59 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/07 20:17:57 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

void	fst_floodfill(int x_pos, int y_pos, t_data *data)
{
	if ((x_pos > data->height || x_pos < 0)
		|| (y_pos > data->width || y_pos < 0))
		return ;
	if (data->dup_buff[x_pos][y_pos] != 'P'
		&& data->dup_buff[x_pos][y_pos] != 'C'
		&& data->dup_buff[x_pos][y_pos] != '0')
		return ;
	data->dup_buff[x_pos][y_pos] = '+';
	fst_floodfill(x_pos + 1, y_pos, data);
	fst_floodfill(x_pos, y_pos + 1, data);
	fst_floodfill(x_pos - 1, y_pos, data);
	fst_floodfill(x_pos, y_pos - 1, data);
	return ;
}

void	scnd_floodfill(int x_pos, int y_pos, t_data *data)
{
	if ((x_pos > data->height || x_pos < 0)
		|| (y_pos > data->width || y_pos < 0))
		return ;
	if (data->dup_buff[x_pos][y_pos] != '+'
		&& data->dup_buff[x_pos][y_pos] != 'E'
		&& data->dup_buff[x_pos][y_pos] != '0')
		return ;
	data->dup_buff[x_pos][y_pos] = '-';
	scnd_floodfill(x_pos + 1, y_pos, data);
	scnd_floodfill(x_pos, y_pos + 1, data);
	scnd_floodfill(x_pos - 1, y_pos, data);
	scnd_floodfill(x_pos, y_pos - 1, data);
	return ;
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

	fst_floodfill(data->player_virtual_pos[0],
		data->player_virtual_pos[1], data);
	while (data->dup_buff[++i])
	{
		j = -1;
		while (data->dup_buff[i][++j])
		{
			if (data->dup_buff[i][j] == 'C')
				print_msg("Collec_ are not all reachable for the player\n", 1);
		}
	}
}

void	check_exit_reachability(t_data *data, int i)
{
	int	j;

	scnd_floodfill(data->player_virtual_pos[0],
		data->player_virtual_pos[1], data);
	while (data->dup_buff[++i])
	{
		j = -1;
		while (data->dup_buff[i][++j])
		{
			if (data->dup_buff[i][j] == 'E')
				print_msg("Exit is not reachable for the player\n", 1);
		}
	}
}
