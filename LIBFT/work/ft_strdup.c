/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:47:37 by ababdelo          #+#    #+#             */
/*   Updated: 2022/11/03 11:59:30 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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
