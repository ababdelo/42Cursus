/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:55:39 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/05 14:26:14 by ababdelo         ###   ########.fr       */
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

void	check_lines_map_length(t_data *data, int i, int cntr)
{
	int	count;

	count = ft_strlen(data->buff, '\n');
	while (data->buff[++i])
	{
		if (data->buff[i] != '\n')
			cntr++;
		else
		{
			if (count != cntr)
				print_msg("lines length doesn't matches !\n", 1);
			cntr = 0;
		}
	}
	if (count != cntr)
		print_msg("lines length doesn't matches !\n", 1);
}

void	check_map_border(t_data *data, int i)
{
	while (data->buff[++i] && data->buff[i] != '\n')
		if (data->buff[i] != '1')
			print_msg("invalid top map's border\n", 1);
	i = -1;
	while (data->buff[++i])
		if (data->buff[i] == '\n' && i > 0)
			if (data->buff[i - 1] != '1' || (data->buff[i + 1] != '1'
					&& data->buff[i + 1] != '\0'))
				print_msg("invalid center map's border\n", 1);
	while (data->buff[--i] != '\n' && i > 0)
		if (data->buff[i] != '1')
			print_msg("invalid bottom map's border\n", 1);
}

void	check_map_construction(t_data *data, int k)
{
	while (data->buff[++k])
	{
		if (data->buff[k] == 'P')
			data->player_cntr++;
		else if (data->buff[k] == 'C')
			data->collect_cntr++;
		else if (data->buff[k] == 'E')
			data->exit_cntr++;
		else if (data->buff[k] != '0' && data->buff[k] != '1'
			&& data->buff[k] != '\n')
			print_msg("map construction, found illegal character!\n", 1);
	}
	if (data->player_cntr != 1)
		print_msg("map constructions, it should be one player!\n", 1);
	else if (data->exit_cntr != 1)
		print_msg("map constructions, it should be one exit!\n", 1);
	else if (data->collect_cntr == 0)
		print_msg("map constructions, it should be at least one collectible!\n",
			1);
}
