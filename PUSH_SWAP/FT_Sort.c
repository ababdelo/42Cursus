/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FT_Sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:58:11 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/05 14:37:17 by ababdelo         ###   ########.fr       */
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

void	sort_largenbr(t_data *data)
{
	t_node	*head_a;

	data->slst = sort_lst(data);
	printf("Stack l :\n");
	print_list(data->slst, 'l');
	while (1)
	{
		head_a = data->stack_a;
		data->size = countlst(head_a);
		data->mid = data->size / 2;
		data->offset = data->size / MGCNBR;
		data->start = data->mid - data->offset;
		data->end = data->mid + data->offset;
		if(data->size == 0)
		{
			while (data->slst != NULL)
				delete_lst(&data->slst, data->slst);
			break;
		}
		approach2sort(data, head_a);
	}
	printf("Stack a :\n");
	print_list(data->stack_a, 'a');
	printf("Stack b :\n");
	print_list(data->stack_b, 'b');
	printf("Stack l :\n");
	print_list(data->slst, 'l');
}
