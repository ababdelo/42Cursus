/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:07:20 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/08 15:46:51 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

void	initialize_data(t_data *data)
{
	data->width = 0;
	data->height = 0;
	data->block_size = 50;
	data->collect_cntr = 0;
	data->player_cntr = 0;
	data->exit_cntr = 0;
	data->player_pos = 0;
	data->player_virtual_pos[0] = 0;
	data->player_virtual_pos[1] = 0;
	data->moves_cntr = 0;
	data->eated_collec_cntr = 0;
	data->dup_buff = NULL;
}

void	initilize_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		print_msg("Error\nfailed initializing !\n", 1);
	data->mlx_win = mlx_new_window(data->mlx, data->width * data->block_size,
			data->height * data->block_size, "Mine Craft");
	if (!data->mlx_win)
		print_msg("Error\nfailed creating new window !\n", 1);
}
