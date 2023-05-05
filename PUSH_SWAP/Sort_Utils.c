/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_Utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:27:35 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/05 14:35:27 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

int	is_sorted(t_node *head)
{
	while (head != NULL && head->next != NULL)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	is_member(t_data *data, int targ, int del)
{
	t_node	*start;
	t_node	*end;
	
	start = get_lst_targ(data->slst, data->start);
	end = get_lst_targ(data->slst, data->end);
	
	while (start != end && start != NULL)
	{
		if (targ == start->value)
		{
			if (del == 1)
				delete_lst(&data->slst, start);
			return (1);
		}
		start = start->next;
	}
	return (0);
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

void	approach2sort(t_data *data, t_node *head_a)
{
	if (is_member(data, head_a->value, 1) || data->size <= 3)
	{
		pb(data);
		if (data->stack_b->value < get_lst_midpos(data->stack_b)->value)
			rb(data);
		head_a = data->stack_a;
	}
	else
	{
		if (which_closer2range(data, head_a->value))
			ra(data);
		else
			rra(data);
	}
}

t_node	*sort_lst(t_data *data)
{
	t_node	*i;
	t_node	*lst;
	
	lst = malloc(sizeof(t_node));
	i = data->stack_a;
	lst->value = i->value;
	lst->next = NULL; 
	if (!lst)
		return NULL;
	i = data->stack_a->next;
	while (i != NULL)
	{
		lst_add_back(lst,i->value);
		i = i->next;
	}
	complete_sort(get_lst_targ(lst, 1));
	return(lst);
}

void	complete_sort(t_node *i)
{
	int		tmp;
	t_node	*j;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->value > j->value)
			{
				tmp = i->value;
				i->value = j->value;
				j->value = tmp;
			}
			j = j->next;
		}
		i = i->next;
	}
}