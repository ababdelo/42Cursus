/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft_Utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <mabdelou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:37:25 by mabdelou          #+#    #+#             */
/*   Updated: 2023/04/28 21:54:19 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

char	*ft_strnstr(const char *str, const char *to_f, int len)
{
	int	x;
	int y;

	x = 0;
	if (to_f[0] == 0)
		return ((char *)&str[x]);
	if (len == 0)
		return (NULL);
	while (str[x] != '\0')
	{
		y = 0;
		while (str[x + y] == to_f[y] && x + y < len)
		{
			if (to_f[y + 1] == '\0')
				return ((char *) &str[x]);
			y++;
		}
		x++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t 	size;
	size_t 	index;

	index = 0;
	if (!s1 || !s2)
		return (NULL);
	size = (ft_strlen(s1) + ft_strlen(s2) + 1);
	dst = malloc (size * sizeof(char));
	if (!dst)
		return (NULL);
	while (index < ft_strlen(s1))
	{
		dst[index] = s1[index];
		index++;
	}
	index = 0;
	while (index < ft_strlen(s2))
	{
		dst[ft_strlen(s1) + index] = s2[index];
		index++;
	}
	dst[size - 1] = '\0';
	return (&dst[0]);
}