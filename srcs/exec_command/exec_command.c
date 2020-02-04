/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 09:42:32 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/04 19:14:59 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		separator(t_data *data)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = data->lst_parsing;
	if (((t_parsing*)(tmp->content))->l_chevron)
	{
		while (((t_parsing*)(tmp->content))->l_chevron)
		{
			tmp = tmp->next;
			data->mypipefd[1] = open(((t_parsing*)(tmp->content))->arg[0],
			O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
			if (((t_parsing*)(tmp->content))->arg[1] != NULL)
				((t_parsing*)(data->lst_parsing->content))->arg =
				add_arg2(((t_parsing*)(data->lst_parsing->content))->arg,
				((t_parsing*)(tmp->content))->arg, data);
		}
		dup2(data->mypipefd[1], STDOUT_FILENO);
	}
	else if (((t_parsing*)(tmp->content))->r_chevron)
	{
		while (((t_parsing*)(tmp->content))->r_chevron)
			tmp = tmp->next;
		i = 0;
		while (((t_parsing*)(tmp->content))->arg[i + 1] != NULL)
			i++;
		data->mypipefd[1] = open(((t_parsing*)(tmp->content))->arg[i], O_RDONLY);
		dup2(data->mypipefd[1], STDIN_FILENO);
	}
	else if (((t_parsing*)(tmp->content))->ld_chevron)
	{
		while (((t_parsing*)(tmp->content))->ld_chevron)
		{
			tmp = tmp->next;
			data->mypipefd[1] = open(((t_parsing*)(tmp->content))->arg[0],
			O_WRONLY | O_APPEND);
			if (((t_parsing*)(tmp->content))->arg[1] != NULL)
				((t_parsing*)(data->lst_parsing->content))->arg =
				add_arg2(((t_parsing*)(data->lst_parsing->content))->arg,
				((t_parsing*)(tmp->content))->arg, data);
		}
		dup2(data->mypipefd[1], STDOUT_FILENO);
	}
	else
		dup2(data->mypipefd[1], STDOUT_FILENO);
	close(data->mypipefd[1]);
}

static void		fork_function(t_parsing *tmp, t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (tmp->l_chevron || tmp->pipe || tmp->r_chevron || tmp->ld_chevron)
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
	if (data->lst_parsing && exec_command_env((t_parsing*)
	(data->lst_parsing->content), data) == 0 && data->lst_parsing->next == NULL)
		fork_function((t_parsing*)(data->lst_parsing->content), data);
	else if (data->lst_parsing && data->lst_parsing->next != NULL)
	{
		fork_function((t_parsing*)(data->lst_parsing->content), data);
		while (data->lst_parsing &&
		(((t_parsing*)(data->lst_parsing->content))->l_chevron ||
		((t_parsing*)(data->lst_parsing->content))->pipe ||
		((t_parsing*)(data->lst_parsing->content))->r_chevron ||
		((t_parsing*)(data->lst_parsing->content))->ld_chevron))
			data->lst_parsing = data->lst_parsing->next;
		data->lst_parsing = data->lst_parsing->next;
		data->status = exec_command(data);
	}
	close(data->mypipefd[0]);
	close(data->mypipefd[1]);
	return (data->status);
}
