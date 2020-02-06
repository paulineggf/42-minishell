/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_chevron.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:20:35 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/06 16:32:46 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		left_chevron(t_list **tmp, t_data *data)
{
	while (((t_parsing*)((*tmp)->content))->l_chevron)
	{
		*tmp = (*tmp)->next;
		data->mypipefd[1] = open(((t_parsing*)((*tmp)->content))->arg[0],
		O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
		if (((t_parsing*)((*tmp)->content))->arg[1] != NULL)
			((t_parsing*)(data->lst_parsing->content))->arg =
			add_arg2(((t_parsing*)(data->lst_parsing->content))->arg,
			((t_parsing*)((*tmp)->content))->arg, data);
	}
	dup2(data->mypipefd[1], STDOUT_FILENO);
}
