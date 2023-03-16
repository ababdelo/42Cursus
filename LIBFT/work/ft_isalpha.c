/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:02:32 by ababdelo          #+#    #+#             */
/*   Updated: 2022/10/30 08:50:02 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	int	res;

	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		res = 1;
	else
		res = 0;
	return (res);
}