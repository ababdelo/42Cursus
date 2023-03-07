/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:44:46 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/07 11:01:24 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

int	ft_strlen(char *str, char c)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index] != c && str[index])
		index++;
	return (index);
}

void	print_msg(char *err, int ret)
{
	write(2, err, ft_strlen(err, '\0'));
	exit(ret);
}

char	*ft_itoa(int nbr)
{
	char	*ptr;
	int		len;
	int		x;

	x = 1;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	len = digit_count(nbr);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (nbr < 0)
	{
		ptr[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		ptr[0] = '0';
	ptr[len] = '\0';
	while (nbr)
	{
		ptr[len - x++] = ((nbr % 10) + '0');
		nbr = nbr / 10;
	}
	return (ptr);
}

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

char	*ft_strdup(char *s1)
{
	int		index;	
	char	*dst;

	index = 0;
	dst = (char *)malloc((ft_strlen(s1, '\0') + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (s1[index] != '\0')
	{
		dst[index] = s1[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
