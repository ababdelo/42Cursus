/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:00:15 by ababdelo          #+#    #+#             */
/*   Updated: 2022/10/31 20:08:22 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *str, const char *to_f, size_t len)
{
	size_t	x;
	size_t	y;

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
