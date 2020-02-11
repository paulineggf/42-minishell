/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:54:55 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/11 14:11:47 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*ft_new_str(char *tab, char *env, t_data *data)
{
	int		i;
	char	*new;

	i = 0;
	free(tab);
	while (env[i] != '=')
		i++;
	i++;
	if (!(new = ft_strdup(&env[i])))
		exit_failure("ft_strdup", data);
	return (new);
}

void			control_env(char **tab, t_data *data)
{
	int		i;
	int		j;
	int		size;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		if (tab[i][0] == '$' && tab[i][1] != '?')
		{
			size = ft_strlen(&tab[i][1]);
			while (data->env[++j])
			{
				if (!ft_strncmp(&tab[i][1], data->env[j], size)
				&& data->env[j][size] == '=')
				{
					tab[i] = ft_new_str(tab[i], data->env[j], data);
					return ;
				}
			}
			if (data->env[j] == NULL)
				tab[i][0] = '\0';
		}
	}
}
