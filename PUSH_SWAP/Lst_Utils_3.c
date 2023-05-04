/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lst_Utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:27:54 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/04 20:50:29 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

int	count_tilltarget(t_node *head, int	targ)
{
	int		index;

	index = 0;
	while (head != NULL && head->value != targ)
	{
		index++;
		head = head->next;
	}
	return (index);
}

int	which_closer(t_data *data, int targ)
{
	int 	size;
	int		r_closer_pos;
	int		l_closer_pos;
	int		right;
	int		left;
	t_node *head;

	size = countlst(data->stack_a);
	r_closer_pos =size;
	l_closer_pos = size;
	head = data->stack_a;
	while(head != NULL)
	{
		if (is_member(data, head->value, 0))
		{
			right = count_tilltarget(data->stack_a, targ);
			left = size -  right;
			if (right < r_closer_pos)
				r_closer_pos = right;
			if( left < l_closer_pos)
				l_closer_pos = left;
		}
		head = head->next;
	}
	if(r_closer_pos < l_closer_pos)
		return(1);
	return(0);
}
