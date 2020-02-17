/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:03:00 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/13 16:49:44 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	exec_command(t_data *data, int inputfd)
{
    char* com[3][3] = { { "/bin/ls", "-la", 0 },
    { "/usr/bin/grep", ".", 0}, { "/bin/cat", "-e", 0 }};

	(void)data;
	(void)inputfd;
    //EXECUTE COMMANDS
    pid_t fork1, fork2, fork3;
    int fd1[2], fd2[2];

    if(pipe(fd1) < 0){
        perror("pipe1");
    }
    if(pipe(fd2) < 0){
        perror("pipe2");
    }


    //COMMAND 1
    fork1 = fork();
    if(fork1 == 0){
        dup2(fd1[1], STDOUT_FILENO);
        close(fd1[0]);
        close(fd2[0]);
        close(fd2[1]);
        execvp(com[0][0], com[0]);
        perror("execvp 1");
        exit(EXIT_FAILURE);
    }

    //COMMAND 2
    fork2 = fork();
    if(fork2 == 0){
        dup2(fd1[0], STDIN_FILENO);
        dup2(fd2[1], STDOUT_FILENO);
        close(fd1[1]);
        close(fd2[0]);
        execvp(com[1][0], com[1]);
        perror("execvp 2");
        exit(EXIT_FAILURE);
    }

    //COMMAND 3
    fork3 = fork();
    if(fork3 == 0){
        dup2(fd2[0], STDIN_FILENO);
        close(fd2[1]);
        close(fd1[0]);
        close(fd1[1]);
        execvp(com[2][0], com[2]);
        perror("execvp 3");
        exit(EXIT_FAILURE);
    }

    close(fd1[0]);
    close(fd1[1]);
    close(fd2[0]);
    close(fd2[1]);

    waitpid(-1, NULL, 0);
    waitpid(-1, NULL, 0);
    waitpid(-1, NULL, 0);

}