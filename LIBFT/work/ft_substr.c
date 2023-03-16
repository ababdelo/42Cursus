/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:00:34 by ababdelo          #+#    #+#             */
/*   Updated: 2022/11/03 13:32:03 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	size;
	size_t	val;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (size - start >= len)
		val = len + 1;
	else
		val = size - start + 1;
	ptr = malloc(val * sizeof(char));
	if (!ptr)
		return (NULL);
	if (len >= SIZE_MAX)
		ft_strlcpy(ptr, &s[start], size +1);
	else
		ft_strlcpy(ptr, (s + start), (len + 1));
	return (ptr);
}
