/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:12:18 by ababdelo          #+#    #+#             */
/*   Updated: 2023/04/01 11:17:44 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (0);	
	else
	{
		t_data	data;
		int	index;

		index = -1;
		initialize_struct(&data, argv);
		fill_struct(&data);
	}	
}
