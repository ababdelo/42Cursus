/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:00:52 by ababdelo          #+#    #+#             */
/*   Updated: 2022/10/31 18:14:10 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	size;
	size_t	index;

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
