/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:15:14 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/17 17:09:10 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**del_env3(char *value, int size, int *i, t_data *data)
{
	char	**new;
	int		j;
	int		k;

	j = 0;
	if (!(new = ft_calloc(*i, sizeof(char*))))
		exit_failure("malloc", data);
	k = 0;
	while (data->env[j])
	{
		if (ft_strncmp(data->env[j], value, size) != 0)
			if (!(new[k++] = ft_strdup(data->env[j])))
				exit_failure("ft_strdup", data);
		free(data->env[j]);
		j++;
	}
	free(data->env);
	return (new);
}

char			**del_env2(int *i, char *value, t_data *data)
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
		data->env = del_env2(&i, tmp->arg[j], data);
		i--;
		data->ret = 0;
		j++;
	}
}
