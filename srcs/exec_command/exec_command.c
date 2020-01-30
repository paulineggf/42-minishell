/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:33:16 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/30 18:31:47 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_command(t_data *data)
{
	pid_t	pid;
	
	if (!data->lst_parsing->next)
	{
		pid = fork();
		if (pid == 0)
		{
			// printf("TEST1\n");
			if (!is_builtin((t_parsing*)(data->lst_parsing->content)))
				if (!(ft_execve(((t_parsing*)(data->lst_parsing->content))->arg[0],
				((t_parsing*)(data->lst_parsing->content))->arg, data->env)))
					ft_printf("pop & max: command not found: %s\n",
					((t_parsing*)(data->lst_parsing->content))->arg[0]);
		}
		else if (pid < 0)
			exit_failure("fork", data);
		else
			waitpid(pid, &data->status, 0);
		// printf("TEST2\n");
	}
	else
	{
		// printf("TEST3\n");
		pid = fork();
		if (pid == 0)
		{
			// printf("TEST4\n");
			if (!is_builtin((t_parsing*)(data->lst_parsing->content)))
				if (!(ft_execve(((t_parsing*)(data->lst_parsing->content))->arg[0],
				((t_parsing*)(data->lst_parsing->content))->arg, data->env)))
					ft_printf("pop & max: command not found: %s\n",
					((t_parsing*)(data->lst_parsing->content))->arg[0]);
		}
		else if (pid < 0)
			exit_failure("fork", data);
		else
			waitpid(pid, NULL, 0);
		// printf("TEST5\n");
		data->lst_parsing = data->lst_parsing->next;
		data->status = exec_command(data);
	}
	// printf("TEST6\n");
	return (data->status);
}
