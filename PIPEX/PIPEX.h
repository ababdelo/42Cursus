/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PIPEX.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:12:11 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/25 16:41:12 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_cmd
{
	int		infile;
	int		outfile;
	char	*cmd;
	char	**args;
	char	**newpaths;
}	t_cmd;

typedef struct s_data
{
	t_cmd	*cmd;
	char	**argv;
	char	**envir;
	char	**paths;
	int		infile_;
	int		outfile_;
	int		cntr_;
}	t_data;

int		wrd_cnt(char const *s, char del);

size_t	ft_strlen(char const *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	**ft_split(char const *s, char c);
char	**ft_free(char **str, int x);
char	*ft_strdup(const char *s1);
char	*ft_strnstr(const char *str, const char *to_f, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

void	choose_action(t_data *data, int index, int cntr);
void	forkproc(t_data *data);
void	closefd(t_data *data);
void	add_cmdname_2_path(t_data *data);
void	get_env_path(t_data *data);
void	fill_cmd_struct(t_data *data);
void	print_msg(char *err, int ret);
void	initialize(t_data *data, char **av, char **ev);
void	check_file_accessebility(t_data *data);
void	check_args(t_data *data);

#endif