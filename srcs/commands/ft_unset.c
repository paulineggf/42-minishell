/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:15:14 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/11 16:00:31 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**del_env(int *i, char **env, char *value, t_data *data)
{
	int			j;
	int			k;
	int			size;
	char		**new;

	j = -1;
	size = ft_strlen(value);
	while (env[++j])
	{
		if (ft_strncmp(env[j], value, size) == 0 && (j = -1))
		{
			if (!(new = ft_calloc(*i, sizeof(char*))))
				exit_failure("malloc", data);
			k = 0;
			while (env[++j])
			{
				if (ft_strncmp(env[j], value, size) != 0)
					if (!(new[k++] = ft_strdup(env[j])))
						exit_failure("ft_strdup", data);
				free(env[j]);
			}
			return (new);
		}
	}
	return (env);
}

void			ft_unset(t_parsing *tmp, t_data *data)
{
	int			i;

	i = 0;
	while (data->env[i])
		i++;
	data->env = del_env(&i, data->env, tmp->arg[1], data);
	data->ret = 0;
	exit(data->ret);
}
