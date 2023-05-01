/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft_Utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <mabdelou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:23:56 by ababdelo          #+#    #+#             */
/*   Updated: 2023/04/29 10:52:06 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

size_t	ft_strlen(const char *str)
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

int	wrd_cnt(char const *s, char del)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[index] != '\0')
	{
		while (s[index] == del)
			index++;
		if (s[index] != '\0')
			count++;
		while (s[index] != del && s[index] != '\0')
			index++;
	}
	return (count);
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
	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '9')
			result = result * 10 + (str[index] - 48);
		else
		{
			data->err = "NAN";
			break;
		}
		index++;
	}
	check_nbr_range(data, result, sgn);
	return (result * sgn);
}
