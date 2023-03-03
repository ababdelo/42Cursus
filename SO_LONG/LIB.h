/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIB.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:40:58 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/03 12:50:13 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define EXIT 53

typedef struct t_data
{
	void	*mlx;
	void	*mlx_win;
	void	*grass_;
	void	*collect_;
	void	*wall_;
	void	*portal_;
	void	*player_;
	char	*buff;
	int		block_size;
	int		height;
	int		width;
	int		collect_cntr;
	int		player_cntr;
	int		exit_cntr;
	int		player_pos;	
	int		moves_cntr;
}	t_data;

int		ft_strlen(char *str, char c);
int		get_key_pressed(int keycode, t_data *data);

char	*check_path_and_get_buff(char *path);

void	initialize(t_data *data);
void	print_error(char *err, int ret);
void	check_map_extention(char *str);
void	check_texture(t_data *data);
void	print2win(t_data *data);
void	get_map_size(t_data *data);
void	check_lines_map_length(t_data *data);
void	check_map_border(t_data *data);
void	check_map_construction(t_data *data);
void	exit_win(t_data *data);
void	move_forward(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	move_backward(t_data *data);

#endif
