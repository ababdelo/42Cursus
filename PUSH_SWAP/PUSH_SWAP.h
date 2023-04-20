/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PUSH_SWAP.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:12:12 by ababdelo          #+#    #+#             */
/*   Updated: 2023/04/01 11:42:59 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef	struct s_node
{
	int	value;
	struct s_node *next;
}t_node;

typedef struct s_data
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**av;
}	t_data;

void	ft_tester(t_data *data);

void	initialize_struct(t_data *data, char **av);
void	print_msg(char *str);
void	fill_list(t_data *data);
void	lst_add_back(t_node *stack_a,int data);
void print_list(t_node *lst, char c);
t_node *ft_getend(t_node *lst);

int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		check_args(t_data *data);

void	delete_lst(t_node **lst, t_node *target);
t_node *get_lst_targ(t_node *lst, int targ);
void	lst_add_front(t_node **lst, int data);
int countlst(t_node *lst);
int	check_repetition(t_data *data);

void	sort_2nbr(t_data *data);
void	sort_3nbr(t_data *data);
void	sort_5nbr(t_data *data);
void	sort_l1hnbr(t_data *data);
void	sort_m1hnbr(t_data *data);

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pb(t_data *data);
void	pa(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
#endif