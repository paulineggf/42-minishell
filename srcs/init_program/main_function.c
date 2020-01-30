/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:49:58 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/30 17:05:14 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_function(t_data *data)
{
	char		*line;

	while (1)
	{
		if ((data->str_prompt = ft_prompt(data)))
			ft_putstr(data->str_prompt);
		if (get_next_line(0, &line) == -1)
			exit_failure("get_next_line", data);
		add_garbage((void**)&line, data);
		data->lst_parsing = NULL;
		data->lst_parsing = parsing_command(line, data);
		data->inputfd = pipe(data->mypipefd);
		data->status = exec_command(data);
		ft_lstclear(&data->garbage_collector, &free);
		if (ft_strcmp(line, "exit\n") == 0)
			break ;
	}
}
