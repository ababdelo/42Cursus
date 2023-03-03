/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:51:34 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/03 12:49:58 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		initialize(&data);
		check_map_extention(argv[1]);
		data.buff = check_path_and_get_buff(argv[1]);
		check_lines_map_length(&data);
		check_map_border(&data);
		check_map_construction(&data);
		get_map_size(&data);
		data.mlx =	mlx_init();
		if (!data.mlx)
			print_error("failed initializing !\n", 1);
		data.mlx_win = mlx_new_window(data.mlx, data.height * data.block_size, data.width * data.block_size, "Hello");
		if (!data.mlx)
			print_error("failed creating new window !\n", 1);
		check_texture(&data);
		print2win(&data);
		mlx_key_hook(data.mlx_win,get_key_pressed,&data);
		mlx_loop(data.mlx);
	}
	else
		print_error("should be two parameters\n", 1);
}