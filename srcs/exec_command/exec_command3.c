make /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:57:32 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/13 13:01:42 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	exec_command(t_data *data, int inputfd)
{
    if (data->lst_parsing && data->lst_parsing->next == NULL)
    {
        pid_t pid;
        int status;
        if ((pid = fork()) == 0)
        {
            if (inputfd != -1)
            {
                dup2(inputfd, STDIN_FILENO);
                close(inputfd);
            }
			ft_execve((t_parsing*)(data->lst_parsing->content), data);	
            perror("execvp");
            exit(EXIT_FAILURE);
        }
        else if (pid < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        waitpid(pid, &status, 0);
    }
    else
    {
        int fds[2];
        if (pipe(fds) != 0)
        {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
        pid_t pid;
        if ((pid = fork()) == 0)
        {
            if (inputfd != -1)
            {
                dup2(inputfd, STDIN_FILENO);
                close(inputfd);
            }
            dup2(fds[1], STDOUT_FILENO);
            close(fds[1]);
			ft_execve((t_parsing*)(data->lst_parsing->content), data);	
            perror("execvp");
            exit(EXIT_FAILURE);
        }
        else if (pid < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
		data->lst_parsing = data->lst_parsing->next;
        exec_command(data, fds[0]);
        waitpid(pid, NULL, 0);
	}
}
	