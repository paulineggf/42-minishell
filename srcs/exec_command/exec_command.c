/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:33:16 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/31 18:47:45 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_command(t_data *data)
{
	pid_t	pid;
	int		savestdout;
	t_list	*tmp;

	savestdout = 0;
	pipe(data->mypipefd);
	if (data->lst_parsing && !data->lst_parsing->next)
	{
		pid = fork();
		if (pid == 0)
		{
			tmp = data->lst_parsing;
			while (((t_parsing*)(tmp->content))->l_chevron)
			{
				printf("TEST1\n");
				if (data->mypipefd[1])
					close(data->mypipefd[1]);
				tmp = tmp->next;
				data->mypipefd[1] = open(((t_parsing*)(tmp->content))->arg[0],
				O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
				dup2(data->mypipefd[1], 1);
			}
			if (!is_builtin((t_parsing*)(data->lst_parsing->content)))
				if (!(ft_execve(((t_parsing*)(data->lst_parsing->content))->arg[0],
				((t_parsing*)(data->lst_parsing->content))->arg, data->env)))
					ft_printf("pop & max: command not found: %s\n",
					((t_parsing*)(data->lst_parsing->content))->arg[0]);
		}
		else if (pid < 0)
			exit_failure("fork", data);
		else
		{
			waitpid(pid, &data->status, 0);
			if (savestdout)
				close(savestdout);
		}
		if (data->mypipefd[0])
			close(data->mypipefd[0]);
		if (data->mypipefd[1])
			close(data->mypipefd[1]);
	}
	else if (data->lst_parsing)
	{
		pid = fork();
		if (pid == 0)
		{
			tmp = data->lst_parsing;
			if (((t_parsing*)(tmp->content))->l_chevron)
			{
				printf("TEST2\n");
				if (data->mypipefd[1])
					close(data->mypipefd[1]);
				tmp = tmp->next;
				data->mypipefd[1] = open(((t_parsing*)(tmp->content))->arg[0],
				O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
				dup2(data->mypipefd[1], 1);
			}	
			if (!is_builtin((t_parsing*)(data->lst_parsing->content)))
				if (!(ft_execve(((t_parsing*)(data->lst_parsing->content))->arg[0],
				((t_parsing*)(data->lst_parsing->content))->arg, data->env)))
					ft_printf("pop & max: %s: command not found\n",
					((t_parsing*)(data->lst_parsing->content))->arg[0]);
		}
		else if (pid < 0)
			exit_failure("fork", data);
		else
		{
			waitpid(pid, NULL, 0);
			if (((t_parsing*)(data->lst_parsing->content))->l_chevron)
				data->lst_parsing = data->lst_parsing->next;
		}
		if (data->mypipefd[0])
			close(data->mypipefd[0]);
		if (data->mypipefd[1])
			close(data->mypipefd[1]);
		if (data->lst_parsing->next)
			data->lst_parsing = data->lst_parsing->next;
		data->status = exec_command(data);
	}
	if (data->mypipefd[0])
		close(data->mypipefd[0]);
	if (data->mypipefd[1])
		close(data->mypipefd[1]);
	return (data->status);
}
