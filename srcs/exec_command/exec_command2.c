/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 09:42:32 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/13 17:48:32 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		separator(t_data *data, int inputfd)
{
	t_list	*tmp;

	(void)inputfd;
	tmp = data->lst_parsing;
	while (1)
	{
		if (((t_parsing*)(tmp->content))->l_chevron)
			left_chevron(&tmp, data);
		else if (((t_parsing*)(tmp->content))->r_chevron)
			right_chevron(&tmp, data);
		else if (((t_parsing*)(tmp->content))->ld_chevron)
			double_left_chevron(&tmp, data);
		else if (((t_parsing*)(tmp->content))->pipe || data->pipe2)
		{
			printf("command : %s\n", ((t_parsing*)(tmp->content))->arg[0]);
			printf("pipe2 : %d\n", data->pipe2);
			if (tmp->next == NULL)
				printf("tmp->next == NULL\n");
			else
				printf("tmp->next != NULL\n");
			
			if (tmp->next != NULL && data->pipe2 == 0)
			{
				printf("1\n\n");
				dup2(data->fd1[1], STDOUT_FILENO);
				close(data->fd1[0]);
				close(data->fd2[0]);
				close(data->fd2[1]);
			}
			if (((t_parsing*)(tmp->content))->pipe && tmp->next != NULL && data->pipe2 == 1)
			{
				printf("2\n\n");
				dup2(data->fd1[0], STDIN_FILENO);
				dup2(data->fd2[1], STDOUT_FILENO);
				close(data->fd1[1]);
				close(data->fd2[0]);
			}
			if (!((t_parsing*)(tmp->content))->pipe && tmp->next == NULL && data->pipe2 == 1)
			{
				printf("3\n\n");
				dup2(data->fd1[0], STDIN_FILENO);
				// dup2(data->fd2[0], STDIN_FILENO);
				close(data->fd2[1]);
				// close(data->fd1[0]);
				close(data->fd1[1]);
				close(data->fd2[0]);
			}	
			break ;
		}
		else
			break ;
	}
	// close(data->fd1[1]);
}

static void		fork_function(t_parsing *tmp, t_data *data, int inputfd)
{
	  char* com[3][3] = { { "/bin/ls", "-la", 0 },
    { "/usr/bin/grep", ".", 0}, { "/bin/cat", "-e", 0 }};
	data->pid = fork();
	minishell_signals2();
	if (data->pid == 0)
	{
		// data->savestdin = dup(STDIN_FILENO);
		// data->savestdout = dup(STDOUT_FILENO);
		separator(data, inputfd);
		if (is_builtin(tmp, data) == 0)
		{
			if (data->pipe2 == 0)
			{
				if (execve(com[0][0], com[0], data->env) == -1)
					exit_failure("FAIL\n", data);
			}
			else if (data->pipe2 == 1)
			{
				// close(data->fd2[1]);
				if (execve(com[2][0], com[2], data->env) == -1)
					exit_failure("FAIL\n", data);			
				ft_putstr_fd("SORTIE3\n", 2);

			}
			// close(data->savestdin);
			// close(data->savestdout);
			// ft_putstr_fd("exec ? \n", 2);
			// if (ft_execve(tmp, data) == 0)
			// {
			// 	ft_putstr_fd("popo & max: ", 2);
			// 	ft_putstr_fd(tmp->arg[0], 2);
			// 	ft_putstr_fd(": command not found\n", 2);
			// 	exit((data->ret = 127));
			// }
		}
	}
	else if (data->pid < 0)
		exit_failure("fork", data);
	// else
	// {

		waitpid(data->pid, &data->status, 0);
		ft_putstr_fd("SORTIE2\n", 2);
		data->ret = WEXITSTATUS(data->status);
	// }
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

void			exec_command(t_data *data, int inputfd)
{
	int		ret;

	ret = 0;
	if (data->lst_parsing)
		ret = exec_command_env((t_parsing*)(data->lst_parsing->content), data);
	if (ret == 0 && data->lst_parsing && data->lst_parsing->next == NULL)
	{
		fork_function((t_parsing*)(data->lst_parsing->content), data, inputfd);
		data->pipe2 = 0;
	}
	else if (ret == 0 && data->lst_parsing && data->lst_parsing->next != NULL)
	{
		fork_function((t_parsing*)(data->lst_parsing->content), data, inputfd);
		if (((t_parsing*)(data->lst_parsing->content))->pipe)
			data->pipe2 = 1;
		else
			data->pipe2 = 0;	
		check_separator(data);
		data->lst_parsing = data->lst_parsing->next;
		exec_command(data, data->fd2[0]);
	}
	else if (ret == 1)
	{
		data->lst_parsing = data->lst_parsing->next;
		exec_command(data, data->fd2[0]);
	}
	close(data->fd1[0]);
	close(data->fd1[1]);
	close(data->fd2[0]);
	close(data->fd2[1]);  
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
}
