/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:24:44 by ababdelo          #+#    #+#             */
/*   Updated: 2022/10/30 11:15:31 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	digit_count(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0 || nbr == 0)
		count ++;
	while (nbr)
	{
		count++;
		nbr = nbr / 10;
	}
	return (count);
}

char	*ft_itoa(int c)
{
	char	*ptr;
	int		len;
	int		x;

	x = 1;
	if (c == -2147483648)
		return (ft_strdup("-2147483648"));
	len = digit_count(c);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (c < 0)
	{
		ptr[0] = '-';
		c = -c;
	}
	if (c == 0)
		ptr[0] = '0';
	ptr[len] = '\0';
	while (c)
	{
		ptr[len - x++] = ((c % 10) + '0');
		c = c / 10;
	}
	return (ptr);
}
