/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:54:55 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/11 17:22:19 by mcraipea         ###   ########.fr       */
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

char			*ft_del_slash(char *str, int j, t_data *data)
{
	int			i;
	int			size;
	char		*dest;

	i = 0;
	size = ft_strlen(str);
	if (!(dest = ft_calloc(sizeof(char), size + 1)))
		exit_failure("ft_calloc", data);
	while (str[i])
	{
		if (str[i] == '\\')
		{
			if (i < size && str[i + 1] == '\\')
			{
				i += 1;
				dest[j++] = str[i++];
			}
			else
				i++;
		}
		else
			dest[j++] = str[i++];
	}
	return (dest);
}

void			ft_else_split(int *i, char *str, char **tab, t_data *data)
{
	ft_line_basic(i, str, tab, data);
	if (str[*i] == '>')
		ft_chevron(i, str, tab, data);
	else if (str[*i] == '<' || str[*i] == ';' || str[*i] == '|')
		ft_other_case(i, str, tab, data);
}
