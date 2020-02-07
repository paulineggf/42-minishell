/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_chevron.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:22:00 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/07 15:43:58 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		right_chevron(t_list **tmp, t_data *data)
{
	int		i;

	i = 0;
	while (((t_parsing*)((*tmp)->content))->r_chevron)
		*tmp = (*tmp)->next;
	while (((t_parsing*)((*tmp)->content))->arg[i + 1] != NULL)
		i++;
	if ((data->mypipefd[1] = open(((t_parsing*)((*tmp)->content))->arg[i], O_RDONLY) == -1))
		ft_printf("popo & max: %s: No such file or directory\n",
		((t_parsing*)((*tmp)->content))->arg[i]);
	data->savestdin = dup(STDIN_FILENO);
	dup2(data->mypipefd[1], STDIN_FILENO);
}
