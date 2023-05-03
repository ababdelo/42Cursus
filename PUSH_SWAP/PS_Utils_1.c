/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_Utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:31:17 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/03 15:52:54 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

void	initialize_prog(t_data *data, char **argv, int ac)
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
		sort_largenbr(data);
}
