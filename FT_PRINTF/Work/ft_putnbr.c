/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:47:47 by ababdelo          #+#    #+#             */
/*   Updated: 2022/11/17 09:55:28 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, int *len)
{
	if (nbr < 0)
	{
		if (nbr == -2147483648)
			ft_putstr("-2147483648", len);
		else
		{
			ft_putchar('-', len);
			ft_putnbr(-nbr, len);
		}
	}
	else if (nbr >= 0 && nbr <= 9)
		ft_putchar((nbr + '0'), len);
	else
	{
		ft_putnbr((nbr / 10), len);
		ft_putnbr((nbr % 10), len);
	}
}
