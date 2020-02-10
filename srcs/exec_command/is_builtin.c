/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:38:48 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/10 12:19:51 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_builtin(t_parsing *parsing, t_data *data)
{
	(void)parsing;
	(void)data;
	if (!ft_strcmp(parsing->arg[0], "echo"))
		return (ft_echo(parsing, data));
	else if (!ft_strcmp(parsing->arg[0], "env"))
		return (ft_env(data));
	else if (!ft_strcmp(parsing->arg[0], "cd"))
	 	return (ft_cd(parsing, data));
	else
		return (0);
	// else if (!ft_strcmp(parsing->arg[0], "pwd"))
	// 	return (ft_pwd(parsing));

}
