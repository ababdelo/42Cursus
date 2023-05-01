/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FT_Sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <mabdelou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:58:11 by ababdelo          #+#    #+#             */
/*   Updated: 2023/04/29 08:40:53 by mabdelou         ###   ########.fr       */
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

void	sort_5nbr(t_data *data)
{
	int	index;
	int	cntr;

	index = -1;
	cntr = countlst(data->stack_a);
	if (cntr == 5)
		push_bgval(Get_bg_lstval(data->stack_a), data);
	push_bgval(Get_bg_lstval(data->stack_a), data);
	sort_3nbr(data, data->stack_a);
	while (++index < 2)
	{
		pa(data);
		ra(data);
		if (cntr == 4)
			break;
	}
}

void	push_bgval(t_node *head, t_data *data)
{
	int	cntr;

	cntr = countlst(head);
	if (cntr == 1)
		rra(data);
	else if (cntr == 2)
	{
		rra(data);
		rra(data);
	}
	if (countlst(data->stack_a) == 5)
	{
		if (cntr == 3)
		{
			ra(data);
			ra(data);
		}
		else if (cntr == 4)
			ra(data);
	}
	else if (countlst(data->stack_a) == 4)
		if (cntr == 3)
			ra(data);
	pb(data);
}

void	sort_more(t_data *data)
{
	(void)*data;
}

