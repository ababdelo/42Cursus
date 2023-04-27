/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lst_Utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:28:14 by ababdelo          #+#    #+#             */
/*   Updated: 2023/04/27 13:14:35 by ababdelo         ###   ########.fr       */
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
