/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:51:42 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/20 15:23:14 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_echo_n(t_parsing *parsing, t_data *data)
{
	int		i;

	i = 1;
	if (parsing->arg[2])
	{
		while (parsing->arg[++i + 1])
		{
			if (!ft_strcmp(parsing->arg[i], "$?"))
				ft_printf(1, "%d ", data->ret);
			else
				ft_printf(1, "%s ", parsing->arg[i]);
		}
		if (!ft_strcmp(parsing->arg[i], "$?"))
			ft_printf(1, "%d", data->ret);
		else
			ft_putstr_fd(parsing->arg[i], 1);
	}
}

static void		ft_echo2(t_parsing *parsing, t_data *data)
{
	int		i;

	i = 1;
	while (parsing->arg[i + 1])
	{
		if (!ft_strcmp(parsing->arg[i], "$?"))
			ft_printf(1, "%d ", data->ret);
		else
			ft_printf(1, "%s ", parsing->arg[i]);
		i++;
	}
	if (!ft_strcmp(parsing->arg[i], "$?"))
		ft_printf(1, "%d\n", data->ret);
	else
		ft_printf(1, "%s\n", parsing->arg[i]);
}

int				ft_echo(t_parsing *parsing, t_data *data)
{
	int		i;

	i = 0;
	if (data->fd1[1] != -1)
	{
		if (parsing->arg[1] != NULL && !ft_strcmp(parsing->arg[1], "-n"))
			ft_echo_n(parsing, data);
		else if (parsing->arg[1] != NULL && ft_strcmp(parsing->arg[1], "-n"))
			ft_echo2(parsing, data);
		else if (parsing->arg[1] == NULL)
			ft_putstr_fd("\n", 1);
		data->ret = 0;
	}
	else
		data->ret = 1;
	dup2(data->savestdout, STDOUT_FILENO);
	dup2(data->savestdin, STDIN_FILENO);
	close(data->savestdout);
	close(data->savestdin);
	exit(data->ret);
	return (1);
}
