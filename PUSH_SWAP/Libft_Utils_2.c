/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft_Utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <mabdelou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:30:26 by mabdelou          #+#    #+#             */
/*   Updated: 2023/04/28 21:52:28 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

char	**ft_free(char **str, int x)
{
	while (x >= 0)
	{
		free(str[x]);
		x--;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	i = 0;
	k = 0;
	str = (char **)malloc((wrd_cnt(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (k < wrd_cnt(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		str[k] = ft_substr(s, j, i - j);
		if (!str[k])
			return (ft_free(str, k));
		k++;
	}
	str[k] = NULL;
	return (str);
}

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

char	*ft_strdup(const char *s1)
{
	int		index;	
	char	*dst;

	index = 0;
	dst = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
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

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	srcsize;

	index = 0;
	srcsize = ft_strlen(src);
	if (dstsize != 0)
	{
		while (src[index] != '\0' && index < dstsize - 1)
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (srcsize);
}
