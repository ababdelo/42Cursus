/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 09:52:22 by ababdelo          #+#    #+#             */
/*   Updated: 2022/11/17 10:17:33 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(const char *form, va_list args, int *x)
{
	if (*form && *form == 'c')
		ft_putchar(va_arg(args, int), x);
	else if (*form && *form == 's')
		ft_putstr(va_arg(args, char *), x);
	else if (*form && *form == 'd')
		ft_putnbr(va_arg(args, int), x);
	else if (*form && *form == 'i')
		ft_putnbr(va_arg(args, int), x);
	else if (*form && *form == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), DEC_BASE, x);
	else if (*form && *form == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), HEX_BASE_LOWER, x);
	else if (*form && *form == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), HEX_BASE_UPPER, x);
	else if (*form && *form == 'p')
	{
		ft_putstr("0x", x);
		ft_putnbr_base(va_arg(args, unsigned long), HEX_BASE_LOWER, x);
	}
	else if (*form == '%')
		ft_putchar('%', x);
}

int	ft_print(const char *form, va_list args, int *len)
{
	while (*form)
	{
		if (*form == '%')
		{
			form++;
			ft_check(form, args, len);
		}
		else
			ft_putchar(*form, len);
		form++;
	}
	return (*len);
}

int	ft_printf(const char *form, ...)
{
	int		len;
	va_list	args;
	int		x;

	x = 0;
	va_start(args, form);
	len = ft_print(form, args, &x);
	va_end(args);
	return (len);
}
