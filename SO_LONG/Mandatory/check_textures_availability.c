/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_availability.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 10:36:19 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/08 15:51:33 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

void	check_textures(t_data *data)
{
	check_blocks_textures(data);
	check_player_collectibles_textures(data);
}

void	check_blocks_textures(t_data *data)
{
	int	width;
	int	height;

	data->dirt_ = mlx_xpm_file_to_image(data->mlx,
			"./textures/Blocks/dirt.xpm", &width, &height);
	if (!data->dirt_)
		print_msg("Error\ncouldn't found dirt texture !\n", 1);
	data->wall_ = mlx_xpm_file_to_image(data->mlx,
			"./textures/Blocks/stone_wall.xpm", &width, &height);
	if (!data->wall_)
		print_msg("Error\ncouldn't found wall texture !\n", 1);
	data->filled_portal_ = mlx_xpm_file_to_image(data->mlx,
			"./textures/Blocks/filled_end_portal.xpm", &width, &height);
	if (!data->filled_portal_)
		print_msg("Error\ncouldn't found filled_portal texture !\n", 1);
	data->empty_portal_ = mlx_xpm_file_to_image(data->mlx,
			"./textures/Blocks/empty_end_portal.xpm", &width, &height);
	if (!data->empty_portal_)
		print_msg("Error\ncouldn't found empty_portal texture !\n", 1);
	return ;
}

void	check_player_collectibles_textures(t_data *data)
{
	int	width;
	int	height;

	data->collect_ = mlx_xpm_file_to_image(data->mlx,
			"./textures/Collectibles/end_eye.xpm", &width, &height);
	if (!data->collect_)
		print_msg("Error\ncouldn't found Collectible texture !\n", 1);
	data->player_ = mlx_xpm_file_to_image(data->mlx,
			"./textures/Player/centered_face.xpm", &width, &height);
	if (!data->player_)
		print_msg("Error\ncouldn't found centered player face texture !\n", 1);
	return ;
}
