/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_Utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:27:35 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/03 17:04:41 by ababdelo         ###   ########.fr       */
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

int	is_member(t_node *sr_lst, t_data *data, int targ)
{
	t_node	*start;
	t_node	*end;
	
	
	start = get_lst_targ(sr_lst, data->start);
	end = get_lst_targ(sr_lst, data->end);
	while (start != end && start != NULL)
	{
		if (targ == start->value)
		{
			delete_lst(&sr_lst, start);
			return (1);
		}
		// sr_lst = sr_lst->next;
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

t_node	*sort_lst(t_data *data)
{
	int		tmp;
	t_node	*i;
	t_node	*j;
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
	i = get_lst_targ(lst, 1);
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
	return(lst);
}
