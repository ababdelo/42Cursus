/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:03:03 by ababdelo          #+#    #+#             */
/*   Updated: 2022/11/03 14:47:22 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int				sgn;
	unsigned long	result;
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
		if (result > 9223372036854775807 && sgn == 1)
			return (-1);
		else if (result > 9223372036854775807 && sgn == -1)
			return (0);
		result = result * 10 + (str[index] - 48);
		index++;
	}
	return (result * sgn);
}
