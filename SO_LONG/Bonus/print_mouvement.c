/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mouvement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:56:31 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/06 10:28:44 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

void	put_str_2_win(t_data *data, int x, int y)
{
	char	*str;

	data->moves_cntr++;
	str = ft_itoa(data->moves_cntr);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall_, 0, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall_, 50, 0);
	mlx_string_put(data->mlx, data->mlx_win, x, y, 16777215, str);
	free(str);
}

int	digit_count(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0 || nbr == 0)
		count ++;
	while (nbr)
	{
		count++;
		nbr = nbr / 10;
	}
	return (count);
}

char	*ft_itoa(int c)
{
	char	*ptr;
	int		len;
	int		x;

	x = 1;
	if (c == -2147483648)
		return (ft_strdup("-2147483648"));
	len = digit_count(c);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (c < 0)
	{
		ptr[0] = '-';
		c = -c;
	}
	if (c == 0)
		ptr[0] = '0';
	ptr[len] = '\0';
	while (c)
	{
		ptr[len - x++] = ((c % 10) + '0');
		c = c / 10;
	}
	return (ptr);
}

char	*ft_strdup(char *s1)
{
	int		index;	
	char	*dst;

	index = 0;
	dst = (char *)malloc((ft_strlen(s1, '\0') + 1) * sizeof(char));
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