/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_Utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:27:35 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/02 23:23:06 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

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

int	*sort_array(t_data *data, int size)
{
	int		*array;
	int		i;
	int		j;
	int		tmp;
	t_node	*head;

	head = data->stack_a;
	i = -1;
	array = malloc(sizeof(int*) * size);
	if (!array)
		return 0;
	while (++i < size)
	{
		array[i] = head->value;
		head = head->next;
	}
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
	return (array);
}
