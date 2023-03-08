/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIB.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:40:58 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/08 15:57:01 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define AR_UP 126
# define AR_DOWN 125
# define AR_RIGHT 124
# define AR_LEFT 123

# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0

# define EXIT 53

# define MAX_BUFFER_SIZE 1500

typedef struct s_pos
{
	int	x_pos;
	int	y_pos;
}	t_pos;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;

	char	*buff;
	char	**dup_buff;

	void	*dirt_;
	void	*wall_;
	void	*collect_;
	void	*empty_portal_;
	void	*filled_portal_;
	void	*player_;

	int		block_size;
	int		height;
	int		width;

	int		collect_cntr;
	int		player_cntr;
	int		exit_cntr;

	int		eated_collec_cntr;

	int		player_pos;
	int		player_virtual_pos[2];
	int		moves_cntr;

	t_pos	*collc_pos;
	t_pos	exit_pos;
}	t_data;

int		ft_strlen(char *str, char c);
int		get_key_pressed(int keycode, t_data *data);
int		exit_win(t_data *data);

char	*check_map_extention_and_get_buff(char *name, char *path);

void	check_exit_reachability(t_data *data, int i);
void	check_collectibles_reachability(t_data *data, int i);
void	chk_p_c_e(t_data *data, int x, int y, int index);
void	print2win(t_data *data, int x, int y, int index);
void	check_rules(t_data *data);
void	check_map_path(t_data *data, int i, int y);
void	floodfill(int x_pos, int y_pos, t_data *data, char c);
void	ft_check(t_data *data, int i, int j);
void	flood_test(t_data *data);
void	get_collectible_pos(t_data *data, int i, int j, int k);
void	get_exit_pos(t_data *data, int i, int j);
void	duplicate_buff(t_data *data, int i, int j, int k);
void	initialize_data(t_data *data);
void	initilize_mlx(t_data *data);
void	print_msg(char *err, int ret);
void	print_msg_2_shell(char *str);
void	check_player_collectibles_textures(t_data *data);
void	check_blocks_textures(t_data *data);
void	check_textures(t_data *data);
void	print2win(t_data *data, int x,	int y, int index);
void	print_msg_2_shell(char *str);
void	get_map_size(t_data *data, int i);
void	check_lines_map_length(t_data *data, int i, int cntr);
void	check_map_border(t_data *data, int i);
void	check_map_construction(t_data *data, int k);
void	check_items_cnt(t_data *data);
void	print_mvm_2_shell(t_data *data);
char	*ft_itoa(int nbr);
char	*ft_strdup(char *s1);
int		digit_count(int nbr);
void	move_forward(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	move_backward(t_data *data);

#endif
