/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FT_Sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:58:11 by ababdelo          #+#    #+#             */
/*   Updated: 2023/04/27 14:04:47 by ababdelo         ###   ########.fr       */
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

void	sort_3nbr(t_data *data, t_node *head)
{
	if (head->value > head->next->value && head->value > head->next->next->value)
	{
		if (head->next->value > head->next->next->value)
		{
			sa(data);
			rra(data);
		}
		else if (head->next->value < head->next->next->value)
			ra(data);
	}
	else if (head->value < head->next->value && head->next->value > head->next->next->value)
	{
		if (head->value > head->next->next->value)
			rra(data);
		else if (head->value < head->next->next->value)
		{
			rra(data);
			sa(data);
		}
	}
	else
	{
		if (head->value < head->next->value && head->value < head->next->next->value)
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
