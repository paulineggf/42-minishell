/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:35:27 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/11 17:33:07 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**add_env(int *i, char **env, char *value, t_data *data)
{
	int			j;
	char		**new;

	if (!(new = ft_calloc(*i + 2, sizeof(char*))))
		exit_failure("malloc", data);
	j = 0;
	while (env[j])
	{
		if (!(new[j] = ft_strdup(env[j])))
			exit_failure("ft_strdup", data);
		j++;
	}
	if (!(new[j] = ft_strdup(value)))
		exit_failure("ft_strdup", data);
	j++;
	new[j] = NULL;
	j = 0;
	while (j < *i)
		free(env[j++]);
	return (new);
}

void			ft_export(t_parsing *tmp, t_data *data)
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
	data->env = del_env2(&i, data->env, buffer, data);
	i = 0;
	while (data->env[i])
		i++;
	data->env = add_env(&i, data->env, tmp->arg[1], data);
	data->ret = 0;
}
