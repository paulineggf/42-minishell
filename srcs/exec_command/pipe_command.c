/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:24:45 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/20 12:15:09 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		pipe_command2(t_parsing *tmp, t_list **lst, t_data *data)
{
	data->pid = fork();
	minishell_signals2();
	if (data->pid == 0)
	{
		dup2(data->fd1[1], STDOUT_FILENO);
		close(data->fd1[0]);
		close(data->fd2[0]);
		close(data->fd2[1]);
		if (is_builtin(tmp, data) == 0)
			if (ft_execve(tmp, data) == 0)
			{
				ft_putstr_fd("popo & max: ", 2);
				ft_putstr_fd(tmp->arg[0], 2);
				ft_putstr_fd(": command not found\n", 2);
				exit((data->status = 127));
			}
	}
	*lst = (*lst)->next;
}

static void		pipe_command3(t_parsing *tmp, t_list **lst, t_data *data)
{
	while (tmp->pipe)
	{
		data->pipe2 += 1;
		data->pid = fork();
		minishell_signals2();
		if (data->pid == 0)
		{
			dup2(data->fd1[0], STDIN_FILENO);
			dup2(data->fd2[1], STDOUT_FILENO);
			close(data->fd1[1]);
			close(data->fd2[0]);
			if (is_builtin(tmp, data) == 0)
				if (ft_execve(tmp, data) == 0)
				{
					ft_putstr_fd("popo & max: ", 2);
					ft_putstr_fd(tmp->arg[0], 2);
					ft_putstr_fd(": command not found\n", 2);
					exit((data->status = 127));
				}
		}
		*lst = (*lst)->next;
		tmp = (*lst)->content;
	}
}

static void		pipe_command4(t_parsing *tmp, t_list **lst, t_data *data)
{
	data->pid = fork();
	minishell_signals2();
	if (data->pid == 0)
	{
		if (data->pipe2 > 0)
		{
			dup2(data->fd2[0], STDIN_FILENO);
			close(data->fd1[0]);
		}
		else
		{
			dup2(data->fd1[0], STDIN_FILENO);
			close(data->fd2[0]);
		}
		close(data->fd1[1]);
		close(data->fd2[1]);
		if (check_separator(lst, data) && is_builtin(tmp, data) == 0)
			if (ft_execve(tmp, data) == 0)
			{
				ft_putstr_fd("popo & max: ", 2);
				ft_putstr_fd(tmp->arg[0], 2);
				ft_putstr_fd(": command not found\n", 2);
				exit((data->status = 127));
			}
	}
}

void			pipe_command_bis(t_parsing *tmp, t_list **lst, t_data *data)
{
	data->pipe2 = 0;
	pipe(data->fd2);
	*lst = (*lst)->next;
	tmp = (*lst)->content;
	pipe_command3(tmp, lst, data);
	tmp = (*lst)->content;
	pipe_command4(tmp, lst, data);
	data->lst_parsing = *lst;
	close(data->fd1[0]);
	close(data->fd1[1]);
	close(data->fd2[0]);
	close(data->fd2[1]);
	waitpid(-1, &data->status, 0);
	waitpid(-1, &data->status, 0);
	waitpid(-1, &data->status, 0);
	data->ret = WEXITSTATUS(data->status);
}

void			pipe_command(t_parsing *tmp, t_list **lst, t_data *data)
{
	data->pipe2 = 0;
	pipe(data->fd2);
	pipe_command2(tmp, lst, data);
	tmp = (*lst)->content;
	pipe_command3(tmp, lst, data);
	tmp = (*lst)->content;
	pipe_command4(tmp, lst, data);
	data->lst_parsing = *lst;
	close(data->fd1[0]);
	close(data->fd1[1]);
	close(data->fd2[0]);
	close(data->fd2[1]);
	waitpid(-1, &data->status, 0);
	waitpid(-1, &data->status, 0);
	waitpid(-1, &data->status, 0);
	data->ret = WEXITSTATUS(data->status);
}
