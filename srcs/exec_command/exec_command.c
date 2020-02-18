/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 09:42:32 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/18 12:53:02 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					check_separator(t_list **lst, t_data *data)
{
	t_list	*tmp;

	tmp = *lst;
	while (1)
	{
		if (((t_parsing*)(tmp->content))->l_chevron)
			left_chevron(&tmp, data);
		else if (((t_parsing*)(tmp->content))->r_chevron)
			right_chevron(&tmp, data);
		else if (((t_parsing*)(tmp->content))->ld_chevron)
			double_left_chevron(&tmp, data);
		else
			break ;
	}
	close(data->fd0[1]);
	return (1);
}

static void			fork_function(t_parsing *tmp, t_list **lst, t_data *data)
{
	data->pid = fork();
	minishell_signals2();
	if (data->pid == 0)
	{
		data->savestdin = dup(STDIN_FILENO);
		data->savestdout = dup(STDOUT_FILENO);
		if (tmp->l_chevron || tmp->r_chevron || tmp->ld_chevron)
			check_separator(lst, data);
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

static void			avance_command(t_list **lst)
{
	while (*lst != NULL && ((t_parsing*)(*lst)->content)->semicolon != 1
	&& ((t_parsing*)(*lst)->content)->pipe != 1)
		*lst = (*lst)->next;
	*lst = (*lst)->next;
}

void				exec_command(t_list **lst, t_data *data)
{
	int		ret;

	ret = 0;
	pipe(data->fd0);
	if (*lst != NULL)
	{
		ret = exec_command_env((*lst)->content, data);
		if (ret == 0)
		{
			if (((t_parsing*)(*lst)->content)->pipe)
				pipe_command((*lst)->content, lst, data);
			else
				fork_function((*lst)->content, lst, data);
		}
		if (*lst)
			avance_command(lst);
		exec_command(lst, data);
	}
	close(data->fd0[0]);
	close(data->fd0[1]);
}
