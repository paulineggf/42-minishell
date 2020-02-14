/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_chevron.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:22:00 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/14 15:51:46 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		right_chevron(t_list **tmp, t_data *data)
{
	int		i;

	i = 0;
	while (((t_parsing*)((*tmp)->content))->r_chevron)
	{
		*tmp = (*tmp)->next;
		while (((t_parsing*)((*tmp)->content))->arg[i + 1] != NULL)
			i++;
		if ((data->fd1[1] = open(((t_parsing*)((*tmp)->content))->arg[i],
		O_RDONLY)) == -1)
		{
			ft_putstr_fd("popo & max: ", 2);
			ft_putstr_fd(((t_parsing*)((*tmp)->content))->arg[i], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			while (((t_parsing*)((*tmp)->content))->r_chevron)
				*tmp = (*tmp)->next;
		}
		else
			dup2(data->fd0[1], STDIN_FILENO);
	}
}
