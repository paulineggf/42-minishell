/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:51:42 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/10 14:27:12 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_echo_n(t_parsing *parsing, t_data *data)
{
	int		i;

	i = 1;
	while (parsing->arg[++i + 1])
	{
		if (!ft_strcmp(parsing->arg[i], "$?"))
			ft_printf("%d ", data->status);
		else
			ft_printf("%s ", parsing->arg[i]);
	}
	if (!ft_strcmp(parsing->arg[i], "$?"))
		ft_printf("%d", data->status);
	else
		ft_putstr_fd(parsing->arg[i], 1);
}

static void		ft_echo2(t_parsing *parsing, t_data *data)
{
	int		i;

	i = 0;
	while (parsing->arg[++i + 1])
	{
		if (!ft_strcmp(parsing->arg[i], "$?"))
			ft_printf("%d ", data->status);
		else
			ft_printf("%s ", parsing->arg[i]);
	}
	if (!ft_strcmp(parsing->arg[i], "$?"))
		ft_printf("%d\n", data->status);
	else
		ft_printf("%s\n", parsing->arg[i]);
}

int				ft_echo(t_parsing *parsing, t_data *data)
{
	int		i;

	i = 0;
	if (data->mypipefd[1] != -1)
	{
		if (parsing->arg[1] != NULL && !ft_strcmp(parsing->arg[1], "-n"))
			ft_echo_n(parsing, data);
		else if (parsing->arg[1] != NULL && ft_strcmp(parsing->arg[1], "-n"))
			ft_echo2(parsing, data);
		else if (parsing->arg[1] == NULL)
			ft_putstr_fd("\n", 1);
		data->status = 0;
	}
	else
		data->status = 1;
	dup2(data->savestdout, STDOUT_FILENO);
	dup2(data->savestdin, STDIN_FILENO);
	return (1);
}
