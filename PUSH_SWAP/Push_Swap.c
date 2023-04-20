/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:08:21 by ababdelo          #+#    #+#             */
/*   Updated: 2023/04/19 13:08:21 by ababdelo         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_data	data;
	if (argc < 3)
		return (0);	
	else
	{
		initialize_struct(&data, argv);
		if (!check_args(&data))
			print_msg("Error ' NAN '\n");
		fill_list(&data);
		//ft_tester(&data);
		if (argc == 3)
			sort_2nbr(&data);
		else if (argc == 4)
			sort_3nbr(&data);
		// else if (argc > 4 && argc <= 6)
		// 	sort_5nbr(&data);
		// else if (argc > 6 && argc <= 101)
		// 	sort_l1hnbr(&data);
		// else
		// 	sort_m1hnbr(&data);
		print_list(data.stack_a, 'a');
	}
}

void ft_tester(t_data *data)
{
	sa(data);
	pb(data);
	pb(data);
	ss(data);
	pb(data);
	rrb(data);
	sa(data);
	pb(data);
	sb(data);
	pb(data);
	rb(data);
	ra(data);
	pb(data);
	sa(data);
	pa(data);
	sa(data);
	pa(data);
	pa(data);
	pa(data);
	pa(data);
	pa(data);
	printf("STACK A :\n");
	print_list(data->stack_a, 'a');
	printf("STACK B :\n");
	print_list(data->stack_b, 'b');
	printf("************************************\n");
}
