/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:09:27 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/06 00:26:36 by ababdelo         ###   ########.fr       */
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

void	check_game_goal(t_data *data, int pos)
{
	if (data->eated_collec_cntr == data->collect_cntr
		&& data->buff[pos] == 'E')
		print_msg("You won!\n", 0);
	else if (data->buff[pos] == 'X')
		print_msg("Player was Slaned by ' ZOMBIE '!\n", 0);
}
