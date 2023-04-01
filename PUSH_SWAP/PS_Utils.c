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
	data->node = NULL;
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
	int	ret;

	i = 0;
	ret = -1;

	while (data->av[++i] != NULL)
	{
		j = -1;
		printf("%s\n", data->av[i]);
		if (data->av[i][0] == '-')
			j++;
		while (data->av[i][++j] != '\0')
		{	
			if (data->av[i][j] >= '0' && data->av[i][j] <= '9')
				ret = 1;
			else
				return(-1);
		}
	}
	return (ret);
}

t_node *ft_getend(t_node *node)
{
	t_node *head = node;

	while(head->next != NULL)
		head = head->next;
	return(head);
}

void lst_add_back(t_node *node,int data)
{
	t_node *node1 = malloc(sizeof(struct s_node) * 1);
	t_node *ptr;
	node1->data = data;
	node1->next = NULL;
	ptr = ft_getend(node);
	ptr->next = node1;
	// printf("node[%d] --> addr : %p | --> data : %d\n",index, ptr, node1->data);
}

void	fill_struct(t_data *data)
{
	int	index;
	t_node	*head;
	
	if (check_args(data) == -1)
		print_msg("Error Found !Digit Char\n", 1);
	head = malloc(sizeof(t_node));
	if (!head)
		print_msg("Error Couldn't Allocate 4 head\n", 1);
	data->node = head;
	index = 0;
	head->data = ft_atoi(data->av[index]);
	head->next = NULL;
	while (data->av[++index] != NULL)
		lst_add_back(data->node, ft_atoi(data->av[index]));
}
