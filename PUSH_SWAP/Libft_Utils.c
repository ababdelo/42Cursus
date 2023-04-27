/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft_Utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:23:56 by ababdelo          #+#    #+#             */
/*   Updated: 2023/04/27 13:47:39 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

int	ft_strlen(char *str)
{
	int	index;
	
	index = 0;
	while (str[index])
		index++;	
	return (index);
}

int	ft_strcmp(char *str, char *ref)
{
	int	index = 0;
	
	index = 0;
	while (str[index] != '\0' || ref[index] != '\0')
	{
		if (str[index] != ref[index])
			return (str[index] - ref[index]);
		index++;
	}
	return (0);
}

void	check_nbr_range(t_data *data, unsigned int nbr, int sgn)
{
	if (nbr > INT_MAX && sgn == 1)
		data->err = "INT_MAX";
	else if (nbr > 2147483648 && sgn == -1)
		data->err = "INT_MIN";
}

int	ft_atoi(t_data *data, char *str)
{
	int				sgn;
	unsigned int	result;
	int				index;

	index = 0;
	result = 0;
	sgn = 1;
	while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sgn = -sgn;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + (str[index] - 48);
		index++;
	}
	check_nbr_range(data, result, sgn);
	return (result * sgn);
}
