/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:24:28 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/14 17:25:31 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		check_separator(t_list **lst, t_data *data)
{
	t_parsing *content;

	while (1)
	{
		content = (*lst)->content;
	
		printf("content->arg[0] : %s\n", content->arg[0]);
	
		if (content->pipe)
			pipe_command(content, lst, data);
		else if (content->l_chevron)
		{
			left_chevron(lst, data);
			ft_putstr_fd("yo\n\n", 2);
		}
		else if (content->r_chevron)
			right_chevron(lst, data);
		else if (content->ld_chevron)
			double_left_chevron(lst, data);
		else
			break ;
		if (*lst == NULL)
		{
			ft_putstr_fd("ICI\n", 2);
			exit_failure(NULL, data);
		}
		
	}
	close(data->fd0[1]);
}

static void		fork_function(t_list **lst, t_data *data)
{
	data->pid = fork();
	minishell_signals2();
	if (data->pid == 0)
	{
		data->savestdin = dup(STDIN_FILENO);
		data->savestdout = dup(STDOUT_FILENO);
		check_separator(lst, data);
	
		printf("command : %s\n", ((t_parsing*)(data->lst_parsing->content))->arg[0]);

		if (is_builtin(data->lst_parsing->content, data) == 0)
		{
			printf("command : %s\n", ((t_parsing*)(data->lst_parsing->content))->arg[0]);
			if (ft_execve(data->lst_parsing->content, data) == 0)
			{
				ft_putstr_fd("popo & max: ", 2);
				ft_putstr_fd(((t_parsing*)(data->lst_parsing->content))->arg[0], 2);
				ft_putstr_fd(": command not found\n", 2);
				exit ((data->ret = 127));
			}
		}
	}
	else if (data->pid < 0)
		exit_failure("fork", data);	
	else
	{
		waitpid(data->pid, &data->status, 0);
		data->ret = WEXITSTATUS(data->status);
		// close(data->fd0[0]);
		// close(data->fd0[1]);
	}
}

static void		avance_command(t_list **lst, t_data *data)
{
	*lst = (*lst)->next;
	printf("semicolon %d\n",  ((t_parsing*)(*lst)->content)->semicolon);

	// Segfault ici

	while (*lst != NULL && ((t_parsing*)(*lst)->content)->semicolon != 1)
		*lst = (*lst)->next;
	printf("semicolon %d\n",  ((t_parsing*)(*lst)->content)->arg[0]);

	data->lst_parsing = *lst;
			printf("command 11: %s\n", ((t_parsing*)(data->lst_parsing->content))->arg[0]);
	
}

void			exec_command(t_list **lst, t_data *data)
{
	if (*lst != NULL)
	{
		pipe(data->fd0);
		fork_function(lst, data);
		avance_command(lst, data);
		exec_command(lst, data);
	}
	close(data->fd0[0]);
	close(data->fd0[1]);
}
