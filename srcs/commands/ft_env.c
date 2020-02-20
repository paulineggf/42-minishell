/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:40:17 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/20 15:23:25 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_env(t_data *data)
{
	int		i;

	i = 0;
	while (data->env[i])
		ft_printf(1, "%s\n", data->env[i++]);
	dup2(data->savestdout, STDOUT_FILENO);
	dup2(data->savestdin, STDIN_FILENO);
	close(data->savestdout);
	close(data->savestdin);
	data->ret = 0;
	exit(data->ret);
	return (1);
}
