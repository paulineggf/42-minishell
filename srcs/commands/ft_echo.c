/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:51:42 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/10 09:50:27 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_echo(t_parsing *parsing, t_data *data)
{
	int		i;

	(void)data;
	i = 1;
	if (parsing->arg[1] != NULL && !ft_strcmp(parsing->arg[1], "-n"))
	{
		while (parsing->arg[++i + 1])
		{
			ft_putstr_fd(parsing->arg[i], 1);
			ft_putstr_fd(" ", 1);
		}
		ft_putstr_fd(parsing->arg[i], 1);
	}
	else if (parsing->arg[1] != NULL && ft_strcmp(parsing->arg[1], "-n"))
	{
		while (parsing->arg[i + 1])
		{
			ft_putstr_fd(parsing->arg[i], 1);
			ft_putstr_fd(" ", 1);
		}
		ft_putstr_fd(parsing->arg[i], 1);
		ft_putstr_fd("\n", 1);
	}
	return (1);
}
