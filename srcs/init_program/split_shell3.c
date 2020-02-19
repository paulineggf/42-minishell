/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:54:55 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/19 16:58:46 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*ft_new_str(int *k, char *env, t_data *data)
{
	int		i;
	char	*new;

	i = 0;
	*k += 1;
	while (env[i] != '=')
		i++;
	i++;
	if (!(new = ft_strdup(&env[i])))
		exit_failure("ft_strdup", data);
	add_garbage((void**)&new, data);
	return (new);
}

char			*control_env(char *tab, t_data *data)
{
	int		j;
	int		k;
	int		size;

	k = 0;
	j = -1;
	if (tab[0] == '$' && tab[1] != '?' && tab[1] != '\0')
	{
		size = ft_strlen(tab) - 1;
		while (data->env[++j])
		{
			if (!ft_strncmp(&tab[1], data->env[j], size)
			&& data->env[j][size] == '=')
				tab = ft_new_str(&k, data->env[j], data);
		}
		if (k == 0)
			tab[0] = '\0';
	}
	return (tab);
}

void			ft_del_slash(int *i, int *j, char *str, char *buf)
{
	int			size;

	size = ft_strlen(str);
	if (str[*i] == '\\')
	{
		if (!(str[*i + 1]))
			buf[*j] = '\0';
		else if (*i < size && str[*i + 1] == '\\')
		{
			*i += 1;
			buf[*j] = str[*i];
			*j += 1;
		}
		else
		{
			*i += 1;
			buf[*j] = str[*i];
			*j += 1;
		}
	}
	else
	{
		buf[*j] = str[*i];
		*j += 1;
	}
}

void			ft_else_split(int *i, char *str, char **tab, t_data *data)
{
	ft_line_basic(i, str, tab, data);
	if (str[*i] == '>')
		ft_chevron(i, str, tab, data);
	else if (str[*i] == '<' || str[*i] == ';' || str[*i] == '|')
		ft_other_case(i, str, tab, data);
}
