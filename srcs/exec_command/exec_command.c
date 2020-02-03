/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 09:42:32 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/03 10:03:10 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		chevron(t_data *data)
{
	data->lst_parsing = data->lst_parsing->next;
	data->mypipefd[1] = open(((t_parsing*)(data->lst_parsing->content))->arg[0],
	O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
	dup2(data->mypipefd[1], 1);
}

static void		fork_function(t_parsing *tmp, t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (tmp->l_chevron)
			chevron(data);
		if (is_builtin(tmp) == 0)
			if (ft_execve(tmp->arg[0], tmp->arg, data->env) == 0)
				ft_printf("pop & max: command not found: %s\n", tmp->arg[0]);
	}
	else if (pid < 0)
		exit_failure("fork", data);
	else
		waitpid(pid, &data->status, 0);
	close(data->mypipefd[0]);		
	close(data->mypipefd[1]);
}

int				exec_command(t_data *data)
{
	t_parsing	*tmp;

	tmp = (t_parsing*)(data->lst_parsing->content);
	pipe(data->mypipefd);
	if (data->lst_parsing->next == NULL)
		fork_function(tmp, data);
	else
	{
		fork_function(tmp, data);
		if (tmp->l_chevron)
			data->lst_parsing = data->lst_parsing->next;
		if (data->lst_parsing->next)
			data->lst_parsing = data->lst_parsing->next;
		data->status = exec_command(data);
	}
	close(data->mypipefd[0]);		
	close(data->mypipefd[1]);
	return (data->status);
}
