/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FT_Sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:58:11 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/03 00:10:24 by ababdelo         ###   ########.fr       */
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
	t_node	*head;
	int	*sorted_arr;
	int	index;
	int	size;
	int	offset;
	int	mid;
	int	start;
	int	end;

	index = -1;
	size = countlst(data->stack_a);
	// printf("\nBefore sorting\n");
	sorted_arr = sort_array(data, size);
	// printf("\nAfter sorting\n");
	// while (++index < size)
	// 	printf("array[%d] : %d\n", index, sorted_arr[index]);
	
	head = data->stack_a;
	while (head != NULL)
	{
		size = countlst(data->stack_a);
		mid = size / 2 - 1;
		offset = size / mid + 1;	
		start = mid - offset;
		end = mid + offset;
		if (is_member(sorted_arr,start, end, head->value))
		{
			pb(data);
			if (head->value < sorted_arr[mid])
				rb(data);
		}
		else
		{
			if (size < size / 2)
				ra(data);
			else
				rra(data);
		}
		head = head->next;
	}
}
