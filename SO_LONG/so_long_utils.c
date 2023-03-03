/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:51:30 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/03 12:52:12 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

void	initialize(t_data *data)
{
	data->height = 0;
	data->width = 0;
	data->block_size = 50;
	data->collect_cntr = 0;
	data->player_cntr = 0;
	data->exit_cntr = 0;
	data->player_pos = 0;
	data->moves_cntr = 0;
}

int	ft_strlen(char *str, char c)
{
	int	index;

	index = 0;
	if (!str)
		return 0;
	while (str[index] != c && str[index])
		index++;
	return (index);
}

void print_error(char *err, int	ret)
{
	write(2,err,ft_strlen(err,'\0'));
	exit(ret);
}

void check_map_extention(char *str)
{
	int	len;

	len = ft_strlen(str,'\0');
	if(len < 5)
		print_error("error in file name !\n", 1);
	if(str[len-1] != 'r' || str[len-2] != 'e'
		|| str[len-3] != 'b' || str[len-4] != '.')
	print_error("error in file name extention!\n", 1);
}

char	*check_path_and_get_buff(char *path)
{
	int		id;
	int		ret;
	char	*buff;
	
	id = open(path, O_RDONLY);
	if (id == -1)
		print_error("failing open file!\n", 1);

	buff = malloc(sizeof(char) * 1024);
	if (!buff)
		print_error("failed allocating buff !\n", 1);
	ret = read(id, buff, 1024);
	if (ret == -1)
		print_error("failing read file!\n", 1);
	buff[ret] = '\0';
	close(id);
	return (buff);
}

void	check_texture(t_data *data)
{
	int width;
	int height;
	data->grass_ = mlx_xpm_file_to_image(data->mlx, "./textures/Blocks/dirt.xpm",  &width, &height);
	if(!data->grass_)
		print_error("couldn't found grass texture !\n", 1);
	data->collect_ = mlx_xpm_file_to_image(data->mlx, "./textures/Collectibles/end_eye.xpm",  &width, &height);
	if(!data->collect_)
		print_error("couldn't found Collectible texture !\n", 1);
	data->wall_ = mlx_xpm_file_to_image(data->mlx, "./textures/Blocks/stone_wall.xpm",  &width, &height);
	if(!data->wall_)
		print_error("couldn't found wall texture !\n", 1);
	data->portal_ = mlx_xpm_file_to_image(data->mlx, "./textures/Blocks/filled_end_portal.xpm",  &width, &height);
	if(!data->portal_)
		print_error("couldn't found portal texture !\n", 1);
	data->player_ = mlx_xpm_file_to_image(data->mlx, "./textures/Player/steve_player.xpm",  &width, &height);
	if(!data->player_)
		print_error("couldn't found player texture !\n", 1);
	return ;
}

void print2win(t_data *data)
{
	int	x;
	int	y;
	int	index;
	
	x = -1;
	y = -1;
	index = -1; 
	while(data->buff[++index])
	{
		if (data->buff[index] == '\n')
		{
			y += data->block_size;
			x = 0;
		}
		else if (data->buff[index] == '1')
			mlx_put_image_to_window(data->mlx,data->mlx_win,data->wall_,x,y);
		else if (data->buff[index] == '0')
			mlx_put_image_to_window(data->mlx,data->mlx_win,data->grass_,x,y);
		else if (data->buff[index] == 'C')
		{
			mlx_put_image_to_window(data->mlx,data->mlx_win,data->grass_,x,y);
			mlx_put_image_to_window(data->mlx,data->mlx_win,data->collect_,x+7,y+7);
		}
		else if (data->buff[index] == 'E')
		{
			mlx_put_image_to_window(data->mlx,data->mlx_win,data->grass_,x,y);
			mlx_put_image_to_window(data->mlx,data->mlx_win,data->portal_,x+2,y+2);
		}
		else if (data->buff[index] == 'P')
		{
			mlx_put_image_to_window(data->mlx,data->mlx_win,data->grass_,x,y);
			mlx_put_image_to_window(data->mlx,data->mlx_win,data->player_,x+2,y+2);
			data->player_pos = index;
		}
		if (data->buff[index] != '\n')
			x += data->block_size;
	}
}

void	get_map_size(t_data *data)
{
	int	index;
	
	index = -1;
	while(data->buff[++index] && data->buff[index] != '\n')
		data->height += 1;
	index = -1;
	while(data->buff[++index])
		if(data->buff[index] == '\n')
			data->width += 1;
	if(data->buff[index] == '\0')
		data->width += 1;
}

void	check_lines_map_length(t_data *data)
{
	int	index;
	int count;
	int count_2;

	count = ft_strlen(data->buff,'\n');
	count_2 = 0;
	index = 0;
	while (data->buff[index])
	{
		if(data->buff[index] != '\n')
			count_2++;
		else
		{
			if (count != count_2)
				print_error("lines length doesn't matches !\n", 1);
			count_2 = 0;
		}
		index++;
	}
	if (count != count_2)
		print_error("lines length doesn't matches !\n", 1);
}

void	check_map_border(t_data *data)
{
	int	index;

	index = -1;
	while (data->buff[++index] && data->buff[index] != '\n')
		if (data->buff[index] != '1')
			print_error("invalid top map's border\n", 1);
	index = -1;
	while(data->buff[++index])
		if (data->buff[index] == '\n' && index > 0)
			if (data->buff[index - 1] != '1' || (data->buff[index + 1] != '1' && data->buff[index + 1] != '\0'))
				print_error("invalid center map's border\n", 1);
	while(data->buff[--index] != '\n' && index > 0)
		if (data->buff[index] != '1')
			print_error("invalid bottom map's border\n", 1);
}

void	check_map_construction(t_data *data)
{
	int	index;

	index = -1;
	while(data->buff[++index])
	{
		if (data->buff[index] == 'P')
			data->player_cntr++;
		else if (data->buff[index] == 'C')
			data->collect_cntr++;
		else if (data->buff[index] == 'E')
			data->exit_cntr++;
		else if (data->buff[index] != '0' && data->buff[index] != '1' && data->buff[index] != '\n')
			print_error("map construction, found illegal character!\n", 1);
	}
	if (data->player_cntr != 1)
		print_error("map constructions, it should be one player!\n", 1);
	else if (data->exit_cntr != 1)
		print_error("map constructions, it should be one exit!\n", 1);
	else if (data->collect_cntr == 0)
		print_error("map constructions, it should be at least one collectible!\n", 1);
}

void	exit_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	print_error("exit successfully !\n", 0);
}

void	move_forward(t_data *data)
{
	int	old_x_pos;
	int	old_y_pos;
	int	new_x_pos;
	int	new_y_pos;
	
	if (data->buff[data->player_pos - data->height - 1] == '0')
	{
		data->buff[data->player_pos] = '0';
		data->buff[data->player_pos - data->height - 1] = 'P';
		old_y_pos = (data->player_pos / (data->height + 1)) * data->block_size;
		old_x_pos = (data->player_pos % (data->height + 1)) * data->block_size;
		new_y_pos = old_y_pos - data->block_size;
		new_x_pos = old_x_pos;
		mlx_put_image_to_window(data->mlx,data->mlx_win,data->grass_,old_x_pos, old_y_pos);
		mlx_put_image_to_window(data->mlx,data->mlx_win,data->player_,new_x_pos + 2, new_y_pos + 2);
		data->player_pos = data->player_pos - data->height - 1;
		data->moves_cntr++;
		printf("Moves : %d\n", data->moves_cntr);
	}
}

void	move_right(t_data *data)
{
	int	old_x_pos;
	int	old_y_pos;
	int	new_x_pos;
	int	new_y_pos;
	
	if (data->buff[data->player_pos + 1] == '0')
	{
		data->buff[data->player_pos] = '0';
		data->buff[data->player_pos + 1] = 'P';
		old_y_pos = (data->player_pos / (data->height + 1)) * data->block_size;
		old_x_pos = (data->player_pos % (data->height + 1)) * data->block_size;
		new_y_pos = old_y_pos;
		new_x_pos = old_x_pos + data->block_size;
		mlx_put_image_to_window(data->mlx,data->mlx_win,data->grass_,old_x_pos, old_y_pos);
		//printf("moved to right %d %d | %d %d\n",old_x_pos,old_y_pos,new_x_pos,new_y_pos);
		mlx_put_image_to_window(data->mlx,data->mlx_win,data->player_,new_x_pos + 2, new_y_pos + 2);
		data->player_pos = data->player_pos + 1;
		data->moves_cntr++;
		printf("Moves : %d\n", data->moves_cntr);
	}
}

void	move_left(t_data *data)
{
	int	old_x_pos;
	int	old_y_pos;
	int	new_x_pos;
	int	new_y_pos;
	
	if (data->buff[data->player_pos - 1] == '0')
	{
		data->buff[data->player_pos] = '0';
		data->buff[data->player_pos - 1] = 'P';
		old_y_pos = (data->player_pos / (data->height + 1)) * data->block_size;
		old_x_pos = (data->player_pos % (data->height + 1)) * data->block_size;
		new_y_pos = old_y_pos;
		new_x_pos = old_x_pos - data->block_size;
		mlx_put_image_to_window(data->mlx,data->mlx_win,data->grass_,old_x_pos, old_y_pos);
		//printf("moved to left [%d] %d %d | %d %d\n",data->player_pos, old_x_pos,old_y_pos,new_x_pos,new_y_pos);
		mlx_put_image_to_window(data->mlx,data->mlx_win,data->player_,new_x_pos + 2, new_y_pos + 2);
		data->player_pos = data->player_pos - 1;
		data->moves_cntr++;
		printf("Moves : %d\n", data->moves_cntr);
	}
}

void	move_backward(t_data *data)
{
	int	old_x_pos;
	int	old_y_pos;
	int	new_x_pos;
	int	new_y_pos;
	
	if (data->buff[data->player_pos + data->height + 1] == '0')
	{
		data->buff[data->player_pos] = '0';
		data->buff[data->player_pos + data->height + 1] = 'P';
		old_y_pos = (data->player_pos / (data->height + 1)) * data->block_size;
		old_x_pos = (data->player_pos % (data->height + 1)) * data->block_size;
		new_y_pos = old_y_pos + data->block_size;
		new_x_pos = old_x_pos;
		mlx_put_image_to_window(data->mlx,data->mlx_win,data->grass_,old_x_pos, old_y_pos);
		mlx_put_image_to_window(data->mlx,data->mlx_win,data->player_,new_x_pos + 2, new_y_pos + 2);
		data->player_pos = data->player_pos + data->height + 1;
		data->moves_cntr++;
		printf("Moves : %d\n", data->moves_cntr);
	}
}

int	get_key_pressed(int keycode, t_data *data)
{
	//printf("%d\n",keycode);
	if (keycode == EXIT)
		exit_win(data);
	else if (keycode == UP)
		move_forward(data);
	else if (keycode == DOWN)
		move_backward(data);
	else if (keycode == RIGHT)
		move_right(data);
	else if (keycode == LEFT)
		move_left(data);
	return (0);
}
