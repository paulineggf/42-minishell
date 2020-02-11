/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:40:17 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/10 16:22:12 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_env(t_data *data)
{
	int		i;

	i = 0;
	while (data->env[i])
		ft_printf("%s\n", data->env[i++]);
	dup2(data->savestdout, STDOUT_FILENO);
	dup2(data->savestdin, STDIN_FILENO);
	close(data->savestdout);
	close(data->savestdin);
	data->ret = 0;
	return (1);
}
