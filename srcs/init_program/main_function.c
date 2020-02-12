/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:49:58 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/12 17:44:57 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_function(t_data *data)
{
	char		*line;
	int			ret;

	minishell_signals();
	while (1)
	{
		if ((data->str_prompt = ft_prompt(data)))
			ft_putstr(data->str_prompt);
		ret = get_next_line(0, &line);
		if (ret == -1)
			exit_failure("get_next_line", data);
		if (ret == 0)
			exit_failure2(data);
		add_garbage((void**)&line, data);
		if (ft_strcmp(line, "exit") == 0)
			exit_failure2(data);
		data->lst_parsing = NULL;
		data->lst_parsing = parsing_command(line, data);
		exec_command(data);
		ft_lstclear(&data->garbage_collector, &free);
	}
}
