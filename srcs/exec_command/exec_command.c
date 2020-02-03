/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 09:42:32 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/03 16:28:57 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		separator(t_data *data)
{
	int		i;
	t_list	*tmp;

	i = 1;
	close(data->mypipefd[0]);
	if (((t_parsing*)(data->lst_parsing->content))->l_chevron)
	{
		tmp = data->lst_parsing->next;
		data->mypipefd[1] = open(((t_parsing*)(tmp->content))->arg[0],
		O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
		if (((t_parsing*)(tmp->content))->arg[1] != NULL)
			((t_parsing*)(data->lst_parsing->content))->arg =
			add_arg2(((t_parsing*)(data->lst_parsing->content))->arg,
			((t_parsing*)(tmp->content))->arg, data);
	}
	dup2(data->mypipefd[1], STDOUT_FILENO);
	close(data->mypipefd[1]);
}

static void		fork_function(t_parsing *tmp, t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (tmp->l_chevron || tmp->pipe)
			separator(data);
		if (is_builtin(tmp) == 0)
			if (ft_execve(tmp->arg[0], tmp->arg, data->env) == 0)
				ft_printf("pop & max: command not found: %s\n", tmp->arg[0]);
	}
	else if (pid < 0)
		exit_failure("fork", data);
	else
	{
		waitpid(pid, &data->status, 0);
		if (tmp->pipe)
		{
			data->lst_parsing = data->lst_parsing->next;
			data->status = exec_command(data);
		}
	}
	close(data->mypipefd[0]);		
	close(data->mypipefd[1]);
}

int				exec_command(t_data *data)
{
	pipe(data->mypipefd);
	if (data->lst_parsing && data->lst_parsing->next == NULL)
		fork_function((t_parsing*)(data->lst_parsing->content), data);
	else if (data->lst_parsing)
	{
		fork_function((t_parsing*)(data->lst_parsing->content), data);
		while (data->lst_parsing &&
		((t_parsing*)(data->lst_parsing->content))->l_chevron)
			data->lst_parsing = data->lst_parsing->next;
		data->lst_parsing = data->lst_parsing->next;
		data->status = exec_command(data);
	}
	close(data->mypipefd[0]);		
	close(data->mypipefd[1]);
	return (data->status);
}
