/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:19:45 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/13 18:46:10 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_error(int flag_double, int flag_simple, t_data *data)
{
	if (flag_double == 1)
		exit_failure("Minishell: Il manque une double quote.\n", data);
	else if (flag_simple == 1)
		exit_failure("Minishell: Il manque une simple quote.\n", data);
}

void			ft_other_case(int *i, char *str, char **tab, t_data *data)
{
	char		buf[256];

	ft_bzero(buf, 256);
	buf[0] = str[*i];
	ft_new_line(buf, tab, data);
	*i += 1;
}

static char		*ft_del_quote2(char *str, int j, t_data *data)
{
	int			i;
	int			size;
	char		*dest;

	i = 0;
	size = ft_strlen(str);
	easy_malloc((void**)&dest, sizeof(char) * (size + 1), data);
	while (str[i])
	{
		if (str[i] == '\'')
		{
			if (i < size)
			{
				if (str[i + 1] == '\'')
					i += 2;
				else
					dest[j++] = str[i++];
			}
		}
		else
			dest[j++] = str[i++];
	}
	return (dest);
}

static char		*ft_del_quote(char *str, int j, t_data *data)
{
	int			i;
	int			size;
	char		*dest;

	i = 0;
	size = ft_strlen(str);
	easy_malloc((void**)&dest, sizeof(char) * (size + 1), data);
	while (str[i])
	{
		if (str[i] == '"')
		{
			if (i < size)
			{
				if (str[i + 1] == '"')
					i += 2;
				else
					dest[j++] = str[i++];
			}
		}
		else
			dest[j++] = str[i++];
	}
	dest = ft_del_quote2(dest, 0, data);
	return (dest);
}

char			**split_shell(char *str, t_data *data)
{
	int			i;
	char		**tab;

	i = 0;
	easy_malloc((void**)&tab, sizeof(char*) * 256, data);
	str = ft_del_quote(str, 0, data);
	str = ft_correctif('"', str, data);
	str = ft_correctif('\'', str, data);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '"')
			ft_double_quote(&i, str, tab, data);
		else if (str[i] == '\'')
			ft_simple_quote(&i, str, tab, data);
		else
			ft_else_split(&i, str, tab, data);
	}
	control_env(tab, data);
	return (tab);
}
