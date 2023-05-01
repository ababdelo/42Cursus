/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:08:21 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/01 15:34:11 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int	ac;
	int	cntr;

	ac = 1;
	if (argc < 3)
		return (0);
	else
	{
		cntr = countlst(data.stack_a);
		initialize_prog(&data, argv, ac);
		if (is_sorted(&data) == 1)
			return (0);
		else
			which_oper(&data, argc, cntr);
		print_list(data.stack_a, 'a');
	}
}