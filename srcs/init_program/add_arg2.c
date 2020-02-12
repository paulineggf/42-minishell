/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_arg2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:38:42 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/12 10:32:52 by pganglof         ###   ########.fr       */
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

	j = 0;
	len_tmp1 = len_tabtab(tmp1);
	len_tmp2 = len_tabtab(tmp2) - 1;
	easy_malloc((void**)&new, sizeof(char*) * (len_tmp1 + len_tmp2 + 1), data);
	fill_str(new, tmp1, &j, data);
	fill_str(new, tmp2 + 1, &j, data);
	return (new);
}
