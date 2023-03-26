/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:23:59 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/19 21:13:07 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PIPEX.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc != 5)
	{
		print_msg("[Error]\n it shouldn't be\
			 more or less than 5 parameters\n", 1);
	}
	else
	{	
		initialize(&data, argv, env);
		check_file_accessebility(&data);
		check_args(&data);
		add_cmdname_2_path(&data);
		forkproc(&data);
	}
	return (0);
}
