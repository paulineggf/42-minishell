/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:46:38 by mcraipea          #+#    #+#             */
/*   Updated: 2020/01/29 19:16:57 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			main(int argc, char **argv, char **env)
{
	t_data		*data;
	char		*str_prompt;
	char		*line;

	(void)argv;
	(void)env;
	if (!(data = ft_calloc(1, sizeof(t_data))))
		return (0);
	garbage_init(data);
	if (argc == 1)
	{
		
		while (1)
		{
			if ((str_prompt = ft_prompt(data)))
				ft_putstr(str_prompt);
			if (get_next_line(0, &line) == -1)
				exit_failure("get_next_line", data);
			add_garbage((void**)&line, data);
			data->lst_parsing = NULL;
			data->lst_parsing = parsing_command(line, data);
			exec_command(data, env);
			// define_command(data);
			ft_lstclear(&data->garbage_collector, &free);
			if (ft_strcmp(line, "exit\n") == 0)
				break ;
		}
	}
	return (0);
}
