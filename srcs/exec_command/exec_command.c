/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 09:42:32 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/12 12:45:47 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		separator(t_data *data)
{
	t_list	*tmp;

	tmp = data->lst_parsing;
	while (1)
	{
		if (((t_parsing*)(tmp->content))->l_chevron)
			left_chevron(&tmp, data);
		else if (((t_parsing*)(tmp->content))->r_chevron)
			right_chevron(&tmp, data);
		else if (((t_parsing*)(tmp->content))->ld_chevron)
			double_left_chevron(&tmp, data);
		else if (((t_parsing*)(tmp->content))->pipe)
		{
			dup2(data->mypipefd[1], STDOUT_FILENO);
			break ;
		}
		else
			break ;
	}
	close(data->mypipefd[1]);
}

static void		fork_function(t_parsing *tmp, t_data *data)
{
	data->pid = fork();
	minishell_signals2();
	if (data->pid == 0)
	{
		data->savestdin = dup(STDIN_FILENO);
		data->savestdout = dup(STDOUT_FILENO);
		if (tmp->l_chevron || tmp->pipe || tmp->r_chevron || tmp->ld_chevron)
			separator(data);
		if (is_builtin(tmp, data) == 0)
			if (ft_execve(tmp, data) == 0)
			{
				ft_putstr_fd("popo & max: ", 2);
				ft_putstr_fd(tmp->arg[0], 2);
				ft_putstr_fd(": command not found\n", 2);
				exit((data->ret = 127));
			}
	}
	else if (data->pid < 0)
		exit_failure("fork", data);
	else
	{
		waitpid(data->pid, &data->status, 0);
		data->ret = WEXITSTATUS(data->status);
	}
}

static void		check_separator(t_data *data)
{
	while (1)
	{
		if (data->lst_parsing
		&& (((t_parsing*)(data->lst_parsing->content))->l_chevron))
			while (((t_parsing*)(data->lst_parsing->content))->l_chevron)
				data->lst_parsing = data->lst_parsing->next;
		else if (data->lst_parsing
		&& (((t_parsing*)(data->lst_parsing->content))->r_chevron))
			while (((t_parsing*)(data->lst_parsing->content))->r_chevron)
				data->lst_parsing = data->lst_parsing->next;
		else if (data->lst_parsing
		&& (((t_parsing*)(data->lst_parsing->content))->ld_chevron))
			while (((t_parsing*)(data->lst_parsing->content))->ld_chevron)
				data->lst_parsing = data->lst_parsing->next;
		else
			break ;
	}
}

void			exec_command(t_data *data)
{
	int		ret;

	ret = 0;
	pipe(data->mypipefd);
	if (data->lst_parsing)
		ret = exec_command_env((t_parsing*)(data->lst_parsing->content), data);
	if (ret == 0 && data->lst_parsing && data->lst_parsing->next == NULL)
		fork_function((t_parsing*)(data->lst_parsing->content), data);
	else if (ret == 0 && data->lst_parsing && data->lst_parsing->next != NULL)
	{
		fork_function((t_parsing*)(data->lst_parsing->content), data);
		check_separator(data);
		data->lst_parsing = data->lst_parsing->next;
		exec_command(data);
	}
	else if (ret == 1)
	{
		data->lst_parsing = data->lst_parsing->next;
		exec_command(data);
	}
	close(data->mypipefd[0]);
	close(data->mypipefd[1]);
}
