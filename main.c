/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:46:38 by mcraipea          #+#    #+#             */
/*   Updated: 2020/01/23 13:36:24 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			main(int argc, char **argv, char **env)
{
	t_data		*data;
	int			end;
	char		*prompt;
	
	garbage_init(data);
	end = 0;
	while (!end)
	{
		prompt = prompt();
			if (prompt != NULL)
				ft_putstr(str);
			//ret = read(0, line, 127);
			//line[ret] = '\0';
			//define_command(line, env);
    	    if (ft_strcmp(line, "exit\n") == 0)
				end = 1;
		}
}