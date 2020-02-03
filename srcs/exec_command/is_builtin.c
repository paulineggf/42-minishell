/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:38:48 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/03 18:50:18 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_builtin(t_parsing *parsing)
{
	(void)parsing;
	if (!ft_strcmp(parsing->arg[0], "echo"))
		return (ft_echo(parsing));
	else
		return (0);
	// else if (!ft_strcmp(parsing->arg[0], "export"))
	// 	return (ft_export(parsing));
	// else if (!ft_strcmp(parsing->arg[0], "cd"))
	// 	return (ft_cd(parsing));
	// else if (!ft_strcmp(parsing->arg[0], "pwd"))
	// 	return (ft_pwd(parsing));
	// else if (!ft_strcmp(parsing->arg[0], "unset"))
	// 	return (ft_unset(parsing));	
	// else if (!ft_strcmp(parsing->arg[0], "env"))
	// 	return (ft_env(parsing));

}
