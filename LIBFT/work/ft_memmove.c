/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:41:38 by ababdelo          #+#    #+#             */
/*   Updated: 2022/10/30 09:00:16 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			x;
	unsigned char	*dest;
	unsigned char	*srcc;

	dest = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	x = 1;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == src)
		return (dst);
	if (srcc < dest)
	{
		while (x <= len)
		{
			dest[len - x] = srcc[len - x];
			x++;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
