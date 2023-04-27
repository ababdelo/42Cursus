/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:08:21 by ababdelo          #+#    #+#             */
/*   Updated: 2023/04/27 13:58:37 by ababdelo         ###   ########.fr       */
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
		check_args(&data);
		fill_list(&data);
		GetErrorRef(&data);
		if (argc == 3)
			sort_2nbr(&data);
		else if (argc == 4)
			sort_3nbr(&data, data.stack_a);
		// else if (argc > 4 && argc <= 6)
		// 	sort_5nbr(&data);
		// else if (argc > 6 && argc <= 101)
		// 	sort_l1hnbr(&data);
		// else
		// 	sort_m1hnbr(&data);
		print_list(data.stack_a, 'a');
	}
}
