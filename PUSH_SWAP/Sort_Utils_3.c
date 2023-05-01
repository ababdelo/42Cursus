/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_Utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:09:22 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/01 14:16:05 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

void	rra(t_data *data)
{
	int tmp,tmp2;
	t_node *ptr;
	ptr = data->stack_a;
	
	tmp = ft_getend(ptr)->value;
	tmp2 = ptr->value;
	ptr->value = tmp;
	while(ptr->next != NULL)
	{
		tmp = ptr->next->value;
		ptr->next->value = tmp2;
		tmp2 =tmp;
		ptr = ptr->next;
	}
	printf("rra\n");
}

void	rrb(t_data *data)
{
	int tmp,tmp2;
	t_node *ptr;
	
	ptr = data->stack_b;
	if (data->stack_b == NULL || countlst(data->stack_b) == 1)
		return ;
	tmp = ft_getend(ptr)->value;
	tmp2 = ptr->value;
	ptr->value = tmp;
	while(ptr->next != NULL)
	{
		tmp = ptr->next->value;
		ptr->next->value = tmp2;
		tmp2 =tmp;
		ptr = ptr->next;
	}
	printf("rrb\n");
}

void	rrr(t_data *data)
{
	int tmp,tmp2;
	t_node *ptr;
	ptr = data->stack_a;
	
	tmp = ft_getend(ptr)->value;
	tmp2 = ptr->value;
	ptr->value = tmp;
	while(ptr->next != NULL)
	{
		tmp = ptr->next->value;
		ptr->next->value = tmp2;
		tmp2 =tmp;
		ptr = ptr->next;
	}
	ptr = data->stack_b;
	if (data->stack_b == NULL || countlst(data->stack_b) == 1)
		return ;
	tmp = ft_getend(ptr)->value;
	tmp2 = ptr->value;
	ptr->value = tmp;
	while(ptr->next != NULL)
	{
		tmp = ptr->next->value;
		ptr->next->value = tmp2;
		tmp2 =tmp;
		ptr = ptr->next;
	}
	printf("rrr\n");
}
