/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:56:58 by ababdelo          #+#    #+#             */
/*   Updated: 2022/11/16 14:39:25 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DEC_BASE "0123456789"
# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<stdarg.h>

size_t	ft_strlen(char *str);

void	ft_putnbr_base(unsigned long nbr, char *base, int *len);
void	ft_putnbr(int nbr, int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);

int		ft_printf(const char *form, ...);

#endif