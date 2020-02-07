/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 09:42:32 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/07 12:06:51 by pganglof         ###   ########.fr       */
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
	if (data->pid == 0)
	{
		if (tmp->l_chevron || tmp->pipe || tmp->r_chevron || tmp->ld_chevron)
			separator(data);
		if (is_builtin(tmp) == 0)
			if (ft_execve(tmp->arg[0], tmp->arg, data->env) == 0)
				ft_printf("popo & max: command not found: %s\n", tmp->arg[0]);
	}
	else if (data->pid < 0)
		exit_failure("fork", data);
	else
		waitpid(data->pid, &data->status, 0);
	close(data->mypipefd[0]);
	close(data->mypipefd[1]);
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

int				exec_command(t_data *data)
{
	int		ret;

	pipe(data->mypipefd);
	ret = 0;
	if (data->lst_parsing)
		ret = exec_command_env((t_parsing*)(data->lst_parsing->content), data);
	if (ret == 0 && data->lst_parsing && data->lst_parsing->next == NULL)
		fork_function((t_parsing*)(data->lst_parsing->content), data);
	else if (ret == 0 && data->lst_parsing && data->lst_parsing->next != NULL)
	{
		fork_function((t_parsing*)(data->lst_parsing->content), data);
		check_separator(data);
		data->lst_parsing = data->lst_parsing->next;
		data->status = exec_command(data);
	}
	else if (ret == 1)
	{
		data->lst_parsing = data->lst_parsing->next;
		data->status = exec_command(data);
	}
	close(data->mypipefd[0]);
	close(data->mypipefd[1]);
	return (data->status);
}
