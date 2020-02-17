/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:38:48 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/14 12:12:48 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_builtin(t_parsing *tmp, t_data *data)
{
	if (!ft_strcmp(tmp->arg[0], "echo"))
		return (ft_echo(tmp, data));
	else if (!ft_strcmp(tmp->arg[0], "env"))
		return (ft_env(data));
	else if (!ft_strcmp(tmp->arg[0], "pwd"))
		return (ft_pwd(data));
	else if (!ft_strcmp(tmp->arg[0], "export"))
	{
		ft_export(tmp, data);
		return (1);
	}
	else if (!ft_strcmp(tmp->arg[0], "unset"))
	{
		ft_unset(tmp, data);
		return (1);
	}
	else
		return (0);
}
