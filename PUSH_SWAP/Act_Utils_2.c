/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Act_Utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:09:13 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/01 15:26:38 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

void	ra(t_data *data)
{
	int tmp;
	t_node *ptr;

	ptr = data->stack_a;
	tmp = data->stack_a->value;
	while(ptr->next != NULL)
	{
		ptr->value = ptr->next->value;
		ptr = ptr->next;
	}
	ptr->value = tmp;
	printf("ra\n");
}

void	rb(t_data *data)
{
	int tmp;
	t_node *ptr;
	
	ptr = data->stack_b;
	if (data->stack_b == NULL || countlst(data->stack_b) == 1)
	return ;
	tmp = data->stack_b->value;
	while(ptr->next != NULL)
	{
		ptr->value = ptr->next->value;
		ptr = ptr->next;
	}
	ptr->value = tmp;
	printf("rb\n");
}

void	rr(t_data *data)
{
	int tmp;
	t_node *ptr;
	
	ptr = data->stack_a;
	tmp = data->stack_a->value;
	while(ptr->next != NULL)
	{
		ptr->value = ptr->next->value;
		ptr = ptr->next;
	}
	ptr->value = tmp;
	ptr = data->stack_b;
	if (data->stack_b == NULL || countlst(data->stack_b) == 1)
	return ;
	tmp = data->stack_b->value;
	while(ptr->next != NULL)
	{
		ptr->value = ptr->next->value;
		ptr = ptr->next;
	}
	ptr->value = tmp;
	printf("rr\n");
}
