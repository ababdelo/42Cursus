/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:55:39 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/08 15:42:37 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

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
				print_msg("Error\nlines length doesn't matches !\n", 1);
			cntr = 0;
		}
	}
	if (count != cntr)
		print_msg("Error\nlines length doesn't matches !\n", 1);
}

void	check_map_border(t_data *data, int i)
{
	while (data->buff[++i] && data->buff[i] != '\n')
		if (data->buff[i] != '1')
			print_msg("Error\ninvalid top map's border\n", 1);
	i = -1;
	while (data->buff[++i])
		if (data->buff[i] == '\n' && i > 0)
			if (data->buff[i - 1] != '1' || (data->buff[i + 1] != '1'
					&& data->buff[i + 1] != '\0'))
				print_msg("Error\ninvalid center map's border\n", 1);
	while (data->buff[--i] != '\n' && i > 0)
		if (data->buff[i] != '1')
			print_msg("Error\ninvalid bottom map's border\n", 1);
}

void	print_msg_2_shell(char *str)
{
	int		len;

	len = ft_strlen(str, '\0');
	write(1, str, len);
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
		{
			print_msg_2_shell("Error\nmap construction, ");
			print_msg("found illegal character!\n", 1);
		}
	}
	check_items_cnt(data);
}

void	check_items_cnt(t_data *data)
{
	if (data->player_cntr != 1)
	{
		print_msg_2_shell("Error\nmap construction, ");
		print_msg("it should contain one player!\n", 1);
	}
	else if (data->exit_cntr != 1)
	{
		print_msg_2_shell("Error\nmap construction, ");
		print_msg("it shouldn't contain more than one exit!\n", 1);
	}
	else if (data->collect_cntr == 0)
	{
		print_msg_2_shell("Error\nmap construction, ");
		print_msg(" it should contain at least one collectible!\n", 1);
	}
}
