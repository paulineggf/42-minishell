/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:33:16 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/29 19:16:51 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_command(t_data *data, char **env)
{
	pid_t	pid;
	int		mypipefd[2];
	int		ret;

	ret = pipe(mypipefd);
	if (ret == -1)
		exit_failure("pipe", data);
	pid = fork();
	if (pid == 0)
	{
		/* Child Process */
		close(mypipefd[0]);
		ft_execve(((t_parsing*)(data->lst_parsing->content))->arg[0], ((t_parsing*)(data->lst_parsing->content))->arg, env);
	}
}
