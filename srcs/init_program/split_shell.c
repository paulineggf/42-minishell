/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:19:45 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/10 18:04:41 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_error(int flag_double, int flag_simple, t_data *data)
{
	if (flag_double == 1)
		exit_failure("Minishell: Il manque un double chevron.\n", data);
	else if (flag_simple == 1)
		exit_failure("Minishell: Il manque un simple chevron.\n", data);
}

static void		ft_other_case(int *i, char *str, char **tab, t_data *data)
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
	if (!(dest = ft_calloc(sizeof(char), size + 1)))
		exit_failure("ft_calloc", data);
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
	if (!(dest = ft_calloc(sizeof(char), size + 1)))
		exit_failure("ft_calloc", data);
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

char		**split_shell(char *str, t_data *data)
{
	int			i;
	char		**tab;

	i = 0;
	if (!(tab = ft_calloc(sizeof(char*) * 256, 1)))
		exit_failure("ft_calloc", data);
	str = ft_del_quote(str, 0, data);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '"')
			ft_double_quote(&i, str, tab, data);
		else if (str[i] == '\'')
			ft_simple_quote(&i, str, tab, data);
		else
		{
			ft_line_basic(&i, str, tab, data);
			if (str[i] == '>')
				ft_chevron(&i, str, tab, data);
			else if (str[i] == '<' || str[i] == ';' || str[i] == '|')
				ft_other_case(&i, str, tab, data);
		}
	}
	control_env(tab, data);
	return (tab);
}
