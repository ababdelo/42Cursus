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

void print_list(t_node *lst)
{
	while ( lst != NULL)
	{
		printf("stack_a[%p] : %d\n",lst, lst->value);
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (0);	
	else
	{
		t_data	data;
		initialize_struct(&data, argv);
		if (!check_args(&data))
			print_msg("Error Found !Digit Char\n", 1);
		fill_list(&data);
		
		printf("before sa\n");
		print_list(data.stack_a);
		sa(&data);
		printf("after sa\n");
		print_list(data.stack_a);
		
		printf("before pb\n");
		print_list(data.stack_a);
		p2b(&data);
		printf("A after pb\n");
		print_list(data.stack_a);
		printf("B after pb\n");
		print_list(data.stack_b);
		
		printf("before pa\n");
		print_list(data.stack_a);
		p2a(&data);
		printf("A after pb\n");
		print_list(data.stack_a);
		printf("B after pb\n");
		print_list(data.stack_b);
	}	
}
