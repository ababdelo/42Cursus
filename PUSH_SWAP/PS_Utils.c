/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_Utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:31:17 by ababdelo          #+#    #+#             */
/*   Updated: 2023/04/01 12:10:35 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

void	initialize_struct(t_data *data, char ** av)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->av = av;
}

void	print_msg(char *str, int ret)
{
	write(2, str, ft_strlen(str));
	exit(ret);
}

int	check_args(t_data *data)
{
	int	i;
	int	j;

	i = 0;

	while (data->av[++i] != NULL)
	{
		j = -1;
		// printf("%s\n", data->av[i]);
		if (data->av[i][0] == '-' || data->av[i][0] == '+')
			j++;
		while (data->av[i][++j] != '\0')
			if (data->av[i][j] < '0' || data->av[i][j] > '9')
				return(0);
	}
	return (1);
}

t_node *ft_getend(t_node *stack_a)
{
	t_node *head = stack_a;

	while(head->next != NULL)
		head = head->next;
	return(head);
}

void	lst_add_front(t_node **lst, int data)
{
	t_node *lst1= malloc(sizeof(t_node));
	lst1->value = data;
	lst1->next = *lst;
	*lst = lst1;
}

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

t_node *get_lst_targ(t_node *lst, int targ)
{
	t_node *head = lst;
	int	cntr = countlst(lst);
	int index = 0;
	while(index < cntr && head != NULL)
	{
		index++;
		if(index == targ)
			break;
		head = head->next;
	}
	return(head);
}

int countlst(t_node *lst)
{
	t_node *head = lst;
	int count = 0;
	while(head != NULL)
	{
		head = head->next;
		count++;
	}
	return(count);
}

void lst_add_back(t_node *stack_a,int data)
{
	t_node *stack_a1 = malloc(sizeof(struct s_node) * 1);
	t_node *ptr;
	stack_a1->value = data;
	stack_a1->next = NULL;
	ptr = ft_getend(stack_a);
	ptr->next = stack_a1;
		// printf("stack_a[%p] | --> data : %d\n", ptr, stack_a1->data);
}

void	fill_list(t_data *data)
{
	int	index;
	t_node	*head;
	
	head = malloc(sizeof(t_node));
	if (!head)
		print_msg("Error Couldn't Allocate 4 head\n", 1);
	data->stack_a = head;
	index = 1;
	head->value = ft_atoi(data->av[index]);
	head->next = NULL;
	while (data->av[++index] != NULL)
		lst_add_back(data->stack_a, ft_atoi(data->av[index]));
}
