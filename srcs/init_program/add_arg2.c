/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_arg2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:38:42 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/03 15:48:28 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		fill_str(char **new, char **tmp, int *j, t_data *data)
{
	int		i;
	int		len;

	i = 0;
	len = len_tabtab(tmp);
	while (i < len)
	{
		if (!(new[*j] = ft_strdup(tmp[i])))
			exit_failure("ft_strdup", data);
		add_garbage((void**)&new[*j], data);
		i++;
		(*j)++;
	}
}

char			**add_arg2(char **tmp1, char **tmp2, t_data *data)
{
	int		j;
	int		len_tmp1;
	int		len_tmp2;
	char	**new;
	t_list	*new_list;

	j = 0;
	len_tmp1 = len_tabtab(tmp1);
	len_tmp2 = len_tabtab(tmp2) - 1;
	if (!(new = ft_calloc(len_tmp1 + len_tmp2 + 1, sizeof(char*))))
		exit_failure("ft_calloc", data);
	if (!(new_list = ft_lstnew(new)))
		exit_failure("ft_lstnew", data);
	ft_lstadd_front(&(data->garbage_collector), new_list);
	fill_str(new, tmp1, &j, data);
	fill_str(new, tmp2++, &j, data);
	return (new);
}
