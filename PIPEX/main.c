/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:23:59 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/16 17:39:44 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

int main (int argc,char **argv,char **env)
{
	t_data data;
	
	if(argc != 5)
		print_msg("[Error]\n it shouldn't be more or less than 5 parameters\n",1);
	else
	{	
		initialize(&data, argv, env);
		check_file_accessebility(&data);
		if (argv[2][0] != '\0' && argv[3][0] != '\0')
			fill_cmd_struct(&data);
		else
			print_msg("[Error]\n it shouldn't be an empty parameter\n",1);
		get_env_path(&data);
		add_cmdname_2_path(&data);
		forkproc(&data);
	}
	return(0);
}
