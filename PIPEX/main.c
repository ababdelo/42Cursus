/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:23:59 by ababdelo          #+#    #+#             */
/*   Updated: 2023/03/09 18:19:18 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIB.h"

int main (int argc,char **argv,char **env)
{
	if(argc != 5)
		print_msg("[Error:] it shouldn't be more or less than 5 parameters\n",1);
	
	t_data data;
	// int	ret;
	// int exit_status = 0;
	// int	pid[2];
	// int index = -1;
	initialize(&data, argv, env);
	check_file_accessebility(&data);
	fill_cmd_struct(&data);
	get_env_path(&data);
	add_cmdname_2_path(&data);
	// while ( ++index < 2)
	// {
	// 	pid[index] = fork();
	// 	if (pid[index] == 0)
	// 	{
	// 		ret = execve();
	// 		exit(0);
	// 	}
	// }
	// index = -1;
	// while ( ++index < 2)
	// 	waitpid(pid[index],&exit_status, 1);
	return(0);
}
