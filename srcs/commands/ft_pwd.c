/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:19:57 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/10 16:22:17 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_pwd(t_data *data)
{
	char	repertoire[4096];

	if (!(getcwd(repertoire, 4096)))
	{
		data->ret = 1;
		return (1);
	}
	ft_printf("%s\n", repertoire);
	dup2(data->savestdout, STDOUT_FILENO);
	dup2(data->savestdin, STDIN_FILENO);
	close(data->savestdout);
	close(data->savestdin);
	data->ret = 0;
	return (1);
}
