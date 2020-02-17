/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:57:32 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/13 18:24:08 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	exec_command(t_data *data, int inputfd, int savestdout)
{
    if (data->lst_parsing && data->lst_parsing->next == NULL)
    {
        pid_t pid;
        int status;
        (void)savestdout;
        // dup2(savestdout, STDOUT_FILENO);
        // close(savestdout);
        if ((pid = fork()) == 0)
        {
            if (inputfd != -1)
            {
                dup2(inputfd, STDIN_FILENO);
                // close(inputfd);

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
        close(inputfd);
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
        // int savestdout;
        // savestdout = dup(STDOUT_FILENO);
        if ((pid = fork()) == 0)
        {
            if (inputfd != -1)
            {
                dup2(inputfd, STDIN_FILENO);
                // close(inputfd);
            }
            dup2(fds[1], STDOUT_FILENO);
            close(fds[0]);
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
        exec_command(data, fds[0], 0);
        close(fds[1]);
        close(fds[0]);
        waitpid(pid, NULL, 0);
        waitpid(pid, NULL, 0);
        // kill(0, SIGINT);
	}
}
	