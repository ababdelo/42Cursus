/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:48:48 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/18 21:21:17 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PIPEX.h"

size_t	ft_strlen(char const *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
		index++;
	return (index);
}

int	wrd_cnt(char const *s, char del)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[index] != '\0')
	{
		while (s[index] == del)
			index++;
		if (s[index] != '\0')
			count++;
		while (s[index] != del && s[index] != '\0')
			index++;
	}
	return (count);
}

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
