/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:04:32 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/28 15:14:24 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	define_command(t_data *data, char **env)
{
	int 	ret;
	char	*path;

	if ((ret = is_it_builtin(data)) >= 0)
		*f[ret](data);
	else if (ft_execve())
		path = is_it_exec(data, env)))

}
