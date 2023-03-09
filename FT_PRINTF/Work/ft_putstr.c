/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:29:46 by ababdelo          #+#    #+#             */
/*   Updated: 2022/11/17 10:19:20 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	int	index;

	index = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		*len = *len + 6;
	}
	while (str && str[index] != '\0')
	{
		ft_putchar(str[index], len);
		index++;
	}
}
