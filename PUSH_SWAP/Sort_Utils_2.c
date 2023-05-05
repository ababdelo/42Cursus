/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_Utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:41:32 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/05 16:48:44 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

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
	complete_sort_task(get_lst_targ(lst, 1));
	return(lst);
}

void	complete_sort_task(t_node *i)
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

void	which_closer2targ(t_data *data, int targ)
{
	
}

void	complete_sort_largenbr(t_data *data)
{
	t_node	*bglstval;
	t_node	*head;

	head = data->stack_b;
	data->size = countlst(head);
	while (1)
	{
		if (data->size == 0)
			break;
		data->size = countlst(head);
		bglstval = Get_bg_lstval(data->head);
		if (head->value == bglstval->value)
		{
			pa(data);
			head = data->stack_a;
		}
		else
		{
			if (which_closer2targ(data, head->value))
				rrb(data);
		}
	}
}