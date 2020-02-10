/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:51:42 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/10 10:55:58 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_echo(t_parsing *parsing, t_data *data)
{
	int		i;

	i = 0;
	if (data->mypipefd[1] != -1)
	{
		if (parsing->arg[1] != NULL && !ft_strcmp(parsing->arg[1], "-n"))
		{
			++i;
			while (parsing->arg[++i + 1])
				ft_printf("%s ", parsing->arg[i]);
			ft_putstr_fd(parsing->arg[i], 1);
		}
		else if (parsing->arg[1] != NULL && ft_strcmp(parsing->arg[1], "-n"))
		{
			while (parsing->arg[++i + 1])
				ft_printf("%s ", parsing->arg[i]);
			ft_printf("%s\n", parsing->arg[i]);
		}
		else if (parsing->arg[1] == NULL)
			ft_putstr_fd("\n", 1);
	}
	dup2(data->savestdout, STDOUT_FILENO);
	dup2(data->savestdin, STDIN_FILENO);
	return (1);
}
