/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:46:38 by mcraipea          #+#    #+#             */
/*   Updated: 2020/01/28 17:55:30 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			main(int argc, char **argv)
{
	//t_data		*data;
	(void)argc;
	(void)argv;
	int			end;
	char		*promp;
	int			ret;
	char		line[128];

	//char 	*argument[] = {"ls",NULL};
	
	//garbage_init(data);
	end = 0;
	
	while (!end)
	{
		//promp = prompt(data);
		promp = "coucou :";
			if (promp != NULL)
				ft_putstr(promp);
			ret = read(0, line, 127);
			line[ret - 1] = '\0';
			//define_command(line, env);
			


			
			char **tab;
			//ft_putstr(line);
			//ft_putstr("\n");
			tab = split_shell(line);
			//ft_putstr("test sortie");
			int i = 0;
			while (tab[i])
			{
				ft_putstr(tab[i]);
				ft_putstr("\n");
				i++;
			}
			ft_bzero(line, 128);
			//ft_execve("ls", argument, env);
    	    //if (ft_strcmp(line, "exit\n") == 0)
			//	end = 1;
		}
	return (0);
}