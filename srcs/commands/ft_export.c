/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:35:27 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/12 15:58:56 by mcraipea         ###   ########.fr       */
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

static int	verif_arg(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_size_env(t_data *data)
{
	int			i;

	i = 0;
	while (data->env[i])
		i++;
	return (i);
}

void		ft_export(t_parsing *tmp, t_data *data)
{
	int			i;
	int			j;
	char		buffer[128];

	j = 1;
	while (tmp->arg[j])
	{
		i = 0;
		if (verif_arg(tmp->arg[j]) == 1)
		{
			while (tmp->arg[j][i] != '=')
			{
				buffer[i] = tmp->arg[j][i];
				i++;
			}
			buffer[i] = tmp->arg[j][i];
			buffer[i] = '\0';
			i = ft_size_env(data);
			data->env = del_env2(&i, data->env, buffer, data);
			i = ft_size_env(data);
			data->env = add_env(&i, data->env, tmp->arg[j], data);
			data->ret = 0;
		}
		j++;
	}
}
