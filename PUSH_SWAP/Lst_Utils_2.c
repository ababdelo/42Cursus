/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lst_Utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:28:14 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/02 20:54:40 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

void	delete_lst(t_node **lst, t_node *target)
{
	t_node *ptr = *lst;
	t_node *backup;
	while (ptr != NULL && target != NULL)
	{
		if (ptr->next == target)
		{
			backup = ptr->next->next;
			free(target);
			ptr->next = backup;
			break;
		}
		else if (ptr == target)
		{
			*lst = ptr->next;
			free(target);
			break;
		}
		ptr = ptr->next;
	}
}

t_node	*Get_bg_lstval(t_node *head)
{
	t_node *ref;

	ref = head;
	while (head != NULL)
	{
		if (ref->value < head->value)
			ref = head;
		head = head->next;
	}
	return (ref);
}

t_node	*Get_sml_lstval(t_node *head)
{
	t_node *ref;

	ref = head;
	while (head != NULL)
	{
		if (ref->value > head->value)
			ref = head;
		head = head->next;
	}
	return (ref);
}

// int	is_member(t_node *start, t_node *end, t_node *targ)
// {
// 	;
// }
