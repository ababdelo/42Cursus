/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:00:55 by ababdelo          #+#    #+#             */
/*   Updated: 2022/11/03 14:50:12 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		index;
	size_t		len;
	char		*ptr;

	ptr = 0;
	index = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[index] && ft_strchr(set, s1[index]))
		index++;
	len = ft_strlen(s1);
	if (ft_strlen(s1) == 0)
		len = 0;
	else
		len = ft_strlen(s1) - 1;
	while (len && ft_strchr(set, s1[len]))
		len--;
	ptr = ft_substr(s1, index, len - index + 1);
	return (ptr);
}
