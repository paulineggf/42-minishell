/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:19:57 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/10 12:29:31 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_pwd(t_data *data)
{
	char	repertoire[4096];

	if (!(getcwd(repertoire, 4096)))
		return (1);
	ft_printf("%s\n", repertoire);
	dup2(data->savestdout, STDOUT_FILENO);
	dup2(data->savestdin, STDIN_FILENO);
	return (1);
}
