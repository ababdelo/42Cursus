/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:09:27 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/05 10:37:05 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

void	check_rules(t_data *data)
{
	check_lines_map_length(data, -1, 0);
	check_map_border(data, -1);
	check_map_construction(data, -1);
}

char	*check_map_extention_and_get_buff(char *name, char *path)
{
	int		id;
	int		ret;
	char	*buff;
	int		len;

	len = ft_strlen(name, '\0');
	if (len < 5)
		print_msg("error in file name !\n", 1);
	if (name[len - 1] != 'r' || name[len - 2] != 'e'
		|| name[len - 3] != 'b' || name[len - 4] != '.')
		print_msg("error in file name extention!\n", 1);
	id = open(path, O_RDONLY);
	if (id == -1)
		print_msg("failing open file!\n", 1);
	buff = malloc(sizeof(char) * MAX_BUFFER_SIZE);
	if (!buff)
		print_msg("failed allocating buff !\n", 1);
	ret = read(id, buff, MAX_BUFFER_SIZE);
	if (ret == -1)
		print_msg("failing read file!\n", 1);
	buff[ret] = '\0';
	close(id);
	return (buff);
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
