/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FT_Check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:05:10 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/01 11:45:48 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

int	is_sorted(t_data *data)
{
	t_node *head;

	head = data->stack_a;
	while (head != NULL && head->next != NULL)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	check_args(t_data *data)
{
	int	j;
	int	i;
	
	i = 0;
	while (data->av[++i] != NULL)
	{
		j = -1;
		if (data->av[i][0] == '-' || data->av[i][0] == '+')
			j++;
		while (data->av[i][++j] != '\0')
		{
			if (data->av[i][j] < '0' || data->av[i][j] > '9')
			{
				data->err = "NAN";
				return ;
			}
		}
	}
}

int	check_repetition(t_data *data)
{
	t_node *head;
	t_node *head2;
	int	cntr;
	
	head = data->stack_a;
	while(head != NULL)
	{
		cntr = 0;
		head2 = data->stack_a;
		while(head2 != NULL)
		{
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
