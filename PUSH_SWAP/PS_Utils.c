/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_Utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:31:17 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/01 11:48:35 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

void	initialize_struct(t_data *data, char ** av)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->av = av;
	data->err = "";
}

void	print_msg(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	fill_list(t_data *data, int ac)
{
	int	index;
	t_node	*head;
	head = malloc(sizeof(t_node));
	if (!head)
		print_msg("Error ' Couldn't Allocate 4 head '\n");
	data->stack_a = head;
	index = ac;
	head->value = ft_atoi(data, data->av[index]);
	head->next = NULL;
	while (data->av[++index] != NULL)
		lst_add_back(data->stack_a, ft_atoi(data, data->av[index]));
	if (check_repetition(data))
		data->err = "DUP";
}

void	GetErrorRef(t_data *data)
{
	if (ft_strcmp(data->err, "NAN") == 0)
		print_msg("Error ' Found a !Digit Number '\n");
	else if (ft_strcmp(data->err, "DUP") == 0 )
		print_msg("Error ' Found Duplicated Numbers '\n");
	else if (ft_strcmp(data->err, "INT_MAX") == 0)
		print_msg("Error ' Number Size is Out of Range  (Nbr >> INT_MAX) '\n");	
	else if (ft_strcmp(data->err, "INT_MIN") == 0)
		print_msg("Error ' Number Size is Out of Range  (Nbr >> INT_MIN) '\n");
}
