/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:35:27 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/18 13:54:22 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**add_env(int *i, char *value, t_data *data)
{
	int			j;
	char		**new;

	if (!(new = ft_calloc(*i + 2, sizeof(char*))))
		exit_failure("malloc", data);
	j = 0;
	while (data->env[j])
	{
		if (!(new[j] = ft_strdup(data->env[j])))
			exit_failure("ft_strdup", data);
		j++;
	}
	if (!(new[j] = ft_strdup(value)))
		exit_failure("ft_strdup", data);
	j++;
	new[j] = NULL;
	j = 0;
	while (j < *i)
		free(data->env[j++]);
	free(data->env);
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

char		**del_env22(int *i, char *value, t_data *data)
{
	int			j;
	int			size;

	j = -1;
	size = ft_strlen(value);
	while (data->env[++j])
	{
		if (ft_strncmp(data->env[j], value, size) == 0)
			return (del_env3(value, size, i, data));
	}
	return (data->env);
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
			buffer[++i] = '\0';
			i = ft_size_env(data);
			data->env = del_env22(&i, buffer, data);
			i = ft_size_env(data);
			data->env = add_env(&i, tmp->arg[j], data);
			data->ret = 0;
		}
		j++;
	}
}
