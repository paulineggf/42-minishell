/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:15:14 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/04 14:27:57 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char			**del_env(int *i, char **env, char *value, t_data *data)
{
	int			j;
	int			k;
	int			l;
	char		**new;

	j = 0;
	while (env[j])
	{
		if (ft_strcmp(env[j], value) == 0)
		{
			if (!(new = ft_calloc(*i, sizeof(char*))))
				exit_failure("malloc", data);
			l = 0;
			k = 0;
			while (env[l])
			{
				if (ft_strcmp(env[l], value) != 0)
				{
					if (!(new[k] = ft_strdup(env[l])))
						exit_failure("ft_strdup", data);
					l++;
					k++;
					new[k] = NULL;
				}
				else
					l++;
			}
			j = 0;
			while (j < *i)
				free(env[j++]);
			return (new);
		}
		j++;
	}
	return (env);
}

void			ft_unset(t_parsing *tmp, t_data *data)
{
	int			i;
	char		buffer[128];

	i = 0;
	while (tmp->arg[1][i] != '=')
	{
		buffer[i] = tmp->arg[1][i];
		i++;
	}
	buffer[i] = tmp->arg[1][i];
	buffer[i] = '\0';
	i = 0;
	while (data->env[i])
		i++;
	data->env = del_env(&i, data->env, buffer, data);
}
