/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FT_Sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:58:11 by ababdelo          #+#    #+#             */
/*   Updated: 2023/04/20 15:58:11 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

void	sort_2nbr(t_data *data)
{
	if (data->stack_a->value > data->stack_a->next->value)
		sa(data);
	else
		return ;
}

void	sort_3nbr(t_data *data)
{
	if (data->stack_a->value > data->stack_a->next->value &&
		data->stack_a->value > data->stack_a->next->next->value)
	{
		if (data->stack_a->next->value > data->stack_a->next->next->value)
		{
			pb(data);
			sa(data);
			pa(data);
			ra(data);
		}
		else if (data->stack_a->next->value < data->stack_a->next->next->value)
			ra(data);
	}
	else if (data->stack_a->value < data->stack_a->next->value &&
			data->stack_a->next->value > data->stack_a->next->next->value)
	{
		if (data->stack_a->value > data->stack_a->next->next->value)
			rra(data);
		else if (data->stack_a->value < data->stack_a->next->next->value)
		{
			rra(data);
			sa(data);
		}
	}
	else
	{
		if (data->stack_a->value < data->stack_a->next->value &&
			data->stack_a->value < data->stack_a->next->next->value)
			return ;
		else
			sa(data);
	}
}

// void	sort_5nbr(t_data *data)
// {
	
// }

// void	sort_l1hnbr(t_data *data)
// {
	
// }

// void	sort_m1hnbr(t_data *data)
// {
	
// }
