/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:50:47 by ababdelo          #+#    #+#             */
/*   Updated: 2022/11/02 10:08:03 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*out;
	size_t			index;

	out = b;
	index = 0;
	while (index < len)
	{
		out[index] = (unsigned char)c;
		index++;
	}
	return (out);
}
