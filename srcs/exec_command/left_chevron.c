/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_chevron.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:20:35 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/14 17:16:17 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		left_chevron(t_list **lst, t_data *data)
{
	t_list	*tmp;
	// t_list	*tmp2;

	tmp = *lst;
	// tmp2 = *lst;
	printf("command 0 : %s\n", ((t_parsing*)((*lst)->content))->arg[0]);

	while (((t_parsing*)((*lst)->content))->l_chevron)
	{
		printf("command 3 : %s\n", ((t_parsing*)((*lst)->content))->arg[0]);

		*lst = (*lst)->next;
		printf("command 4 : %s\n", ((t_parsing*)((*lst)->content))->arg[0]);

		data->fd0[1] = open(((t_parsing*)((*lst)->content))->arg[0],
		O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
		if (((t_parsing*)((*lst)->content))->arg[1] != NULL)
			((t_parsing*)(tmp->content))->arg =
			add_arg2(((t_parsing*)(tmp->content))->arg,
			((t_parsing*)((*lst)->content))->arg, data);
	}
	printf("command 1 : %s\n", ((t_parsing*)((*lst)->content))->arg[0]);
	printf("command 5 : %s\n", ((t_parsing*)(tmp->content))->arg[0]);

	dup2(data->fd0[1], STDOUT_FILENO);
}
