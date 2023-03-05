/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:55:39 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/05 10:24:49 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

void	floodfill(int x_pos, int y_pos, t_data *data)
{
	if ((x_pos > data->height || x_pos < 0)
		|| (y_pos > data->width || y_pos < 0))
		return ;
	if (data->dup_buff[x_pos][y_pos] == '1'
		|| data->dup_buff[x_pos][y_pos] == 'x')
		return ;
	data->dup_buff[x_pos][y_pos] = 'x';
	floodfill(x_pos + 1, y_pos, data);
	floodfill(x_pos, y_pos + 1, data);
	floodfill(x_pos - 1, y_pos, data);
	floodfill(x_pos, y_pos - 1, data);
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
	floodfill(data->player_virtual_pos[0], data->player_virtual_pos[1], data);
	i = -1;
	while (data->dup_buff[++i])
	{
		j = -1;
		while (data->dup_buff[i][++j])
		{
			if (data->dup_buff[i][j] == 'C')
				print_msg("Collectibles are not reachable for the player\n", 1);
			else if (data->dup_buff[i][j] == 'E')
				print_msg("Exit is not reachable for the player\n", 1);
		}
	}
}
