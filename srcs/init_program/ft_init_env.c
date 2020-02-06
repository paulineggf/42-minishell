/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:34:39 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/04 13:15:12 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**ft_init_env(char **env, t_data *data)
{
	int			j;
	char		**new;
	// t_list		*new_list;

	j = 0;
	while (env[j])
		j++;
	if (!(new = ft_calloc(j + 1, sizeof(char*))))
		exit_failure("malloc", data);
	// if (!(new_list = ft_lstnew(new)))
		// exit_failure("ft_lstnew", data);
	// ft_lstadd_front(&(data->garbage_collector), new_list);
	j = 0;
	while (env[j])
	{
		if (!(new[j] = ft_strdup(env[j])))
			exit_failure("ft_strdup", data);
		// add_garbage((void**)&new[j], data);
		j++;
	}
	new[j] = NULL;
	return (new);
}

