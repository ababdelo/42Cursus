/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:57:53 by ababdelo          #+#    #+#             */
/*   Updated: 2022/10/30 08:52:10 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	alpha;
	int		len;

	alpha = (char) c;
	index = 0;
	len = ft_strlen(s);
	if (!s)
		return (NULL);
	while (index <= len)
	{
		if (s[index] == alpha)
			return ((char *)&s[index]);
		index++;
	}
	return (NULL);
}
