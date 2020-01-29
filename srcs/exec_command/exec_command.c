/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:33:16 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/29 17:45:04 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_command(t_data *data)
{
	pid_t	pid;
	int		status;

	if (!data->lst_parsing->next)
	{
		if ((pid = fork()) == 0)
		{
			if ()
		}
	}
}
