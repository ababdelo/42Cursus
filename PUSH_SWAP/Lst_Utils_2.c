/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lst_Utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:28:14 by ababdelo          #+#    #+#             */
/*   Updated: 2023/04/20 11:28:14 by ababdelo         ###   ########.fr       */
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

int	check_repetition(t_data *data)
{
	t_node *head = data->stack_a;
	t_node *head2;
	int	cntr;
	// printf("here\n");
	while(head != NULL)
	{
		cntr = 0;
		head2 = data->stack_a;
		// printf("here1\n");
		while(head2 != NULL)
		{
			// printf("here2\n");
			if(head->value == head2->value)
				cntr++;
			head2 = head2->next;
		}
		if(cntr > 1)
			return(1);
		head = head->next;
	}
	return(0);
}
