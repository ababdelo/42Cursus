/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:51:34 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/08 15:54:35 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		initialize_data(&data);
		data.buff = check_map_extention_and_get_buff(argv[1], argv[1]);
		get_map_size(&data, -1);
		check_rules(&data);
		duplicate_buff(&data, 0, 0, 0);
		get_exit_pos(&data, -1, -1);
		get_collectible_pos(&data, -1, -1, -1);
		get_enemy_pos(&data, -1, -1, -1);
		check_map_path(&data, -1, -1);
		initialize_mlx(&data);
		check_textures(&data);
		print2win(&data, -1, -1, -1);
		put_mouvement_2_win(&data, 10, 10);
		mlx_loop_hook(data.mlx, animate, &data);
		mlx_hook(data.mlx_win, 2, 0, get_key_pressed, &data);
		mlx_hook(data.mlx_win, 17, 0, exit_win, &data);
		mlx_loop(data.mlx);
	}
	else
		print_msg("Error\n should not be more or less than two parameters\n", 1);
}
