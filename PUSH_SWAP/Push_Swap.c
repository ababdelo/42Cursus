/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <mabdelou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:08:21 by ababdelo          #+#    #+#             */
/*   Updated: 2023/04/29 10:21:54 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

void print_list(t_node *lst, char c)
{
	while ( lst != NULL)
	{
		printf("stack_%c[%p] : %d\n",c,lst, lst->value);
		lst = lst->next;
	}
}

void	do_first(t_data *data, char **argv, int ac)
{
	initialize_struct(data, argv);
	check_args(data);
	fill_list(data, ac);
	GetErrorRef(data);
}

void	which_oper(t_data *data, int argc, int cntr)
{
	if (argc == 3 || cntr == 2)
		sort_2nbr(data);
	else if (argc == 4 ||  cntr == 3)
		sort_3nbr(data, data->stack_a);
	else if ((argc > 4 && argc <= 6) ||  (cntr > 3 && cntr <= 5))
		sort_5nbr(data);
	else
		sort_more(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int	ac;
	int	cntr;

	ac = 1;
	if (argc == 1 || (argc == 2 && ft_strcmp(argv[1], "") == 0))
		return (1);
	else
	{
		if (argc == 2)
		{
			argv = ft_split(argv[1], ' ');
			ac = 0;
		}
		do_first(&data, argv, ac);
		cntr = countlst(data.stack_a);
		if (is_sorted(&data) == 1)
			return (0);
		else
			which_oper(&data, argc, cntr);
		print_list(data.stack_a, 'a');
	}
}
