/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:15:14 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/12 15:52:08 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**del_env2(int *i, char **env, char *value, t_data *data)
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
	int			j;

	i = 0;
	j = 1;
	while (tmp->arg[j])
	{
		while (data->env[i])
			i++;
		data->env = del_env2(&i, data->env, tmp->arg[j], data);
		data->ret = 0;
		j++;
	}
}
