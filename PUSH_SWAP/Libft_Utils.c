/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft_Utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:23:56 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/30 14:30:17 by ababdelo         ###   ########.fr       */
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

int	ft_atoi(char *str)
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
		if (result > INT_MAX && sgn == 1)
			return (-1);
		else if (result > 2147483648 && sgn == -1)
			return (-1);
		result = result * 10 + (str[index] - 48);
		index++;
	}
	return (result * sgn);
}