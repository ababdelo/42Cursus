/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:58:50 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/25 16:41:20 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PIPEX.h"

void	print_msg(char *err, int ret)
{
	write(2, err, ft_strlen(err));
	if (ret == 1)
		exit(ret);
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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
				return ((char *) &str[x + 5]);
			y++;
		}
		x++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	size;
	size_t	index;

	index = 0;
	if (!s1 || !s2)
		return (NULL);
	size = (ft_strlen(s1) + ft_strlen(s2) + 2);
	dst = malloc (size * sizeof(char));
	if (!dst)
		return (NULL);
	while (index < ft_strlen(s1))
	{
		dst[index] = s1[index];
		index++;
	}
	dst[index] = '/';
	index = 0;
	while (index < ft_strlen(s2))
	{
		dst[ft_strlen(s1) + index + 1] = s2[index];
		index++;
	}
	dst[size - 1] = '\0';
	return (&dst[0]);
}
