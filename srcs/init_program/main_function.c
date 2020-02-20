/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:49:58 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/20 15:22:09 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_command(t_data *data)
{
	int		ret;
	char	buf[2];
	char	*line;

	line = NULL;
	dup2(data->savestdout, STDOUT_FILENO);
	data->savestdout = dup(STDOUT_FILENO);
	while ((ret = read(0, buf, 1)) >= 0)
	{
		buf[ret] = '\0';
		if (ret == 0 && line == NULL)
			exit_failure2(0, NULL, NULL, data);
		else if (ret == 0)
			ft_printf(1, "%c%c\b\b", 0x7f, 0x7f);
		if (buf[0] == '\n')
			break ;
		if (!(line = ft_strjoin(line, buf)))
			exit_failure("ft_strjoin", data);
		add_garbage((void**)&line, data);
	}
	if (ret == -1)
		exit_failure("get_next_line", data);
	return (line);
}

void	main_function(t_data *data)
{
	char		*line;

	data->savestdin = dup(STDIN_FILENO);
	data->savestdout = dup(STDOUT_FILENO);
	minishell_signals();
	while (1)
	{
		line = NULL;
		if ((data->str_prompt = ft_prompt(data)))
			ft_putstr(data->str_prompt);
		line = get_command(data);
		data->lst_parsing = NULL;
		data->lst_parsing = parsing_command(line, data);
		exec_command(&data->lst_parsing, data);
		ft_lstclear(&data->garbage_collector, &free);
	}
}
