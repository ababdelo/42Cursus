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

void	print_msg(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
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

void	fill_list(t_data *data)
{
	int	index;
	t_node	*head;
	head = malloc(sizeof(t_node));
	if (!head)
		print_msg("Error ' Couldn't Allocate 4 head '\n");
	data->stack_a = head;
	index = 1;
	head->value = ft_atoi(data->av[index]);
	head->next = NULL;
	while (data->av[++index] != NULL)
		lst_add_back(data->stack_a, ft_atoi(data->av[index]));
	if (check_repetition(data))
		print_msg("Error ' Found Duplicated Number '\n");
}
