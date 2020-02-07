/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:19:45 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/07 17:17:19 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_error(int flag_double, int flag_simple, t_data *data)
{
	if (flag_double == 1)
		exit_failure("Minishell: Il manque un double chevron.\n", data);
	else if (flag_simple == 1)
		exit_failure("Minishell: Il manque un simple chevron.\n", data);
}

void		ft_other_case(int *i, char *str, char **tab)
{
	char		buf[256];

	ft_bzero(buf, 256);
	buf[0] = str[*i];
	ft_new_line(buf, tab);
	*i += 1;
}

char		*ft_del_quote2(char *str)
{
	int			i;
	int			j;
	int			size;
	char		*dest;

	i = 0;
	j = 0;
	size = ft_strlen(str);
	dest = calloc(sizeof(char), size + 1);
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

char		*ft_del_quote(char *str)
{
	int			i;
	int			j;
	int			size;
	char		*dest;

	i = 0;
	j = 0;
	size = ft_strlen(str);
	dest = calloc(sizeof(char), size + 1);
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
	return (dest);
}

char		**split_shell(char *str, t_data *data)
{
	int			i;
	char		**tab;

	i = 0;
	tab = ft_calloc(sizeof(char*) * 128, 1);
	str = ft_del_quote(str);
	str = ft_del_quote2(str);
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
			ft_line_basic(&i, str, tab);
			if (str[i] == '>')
				ft_chevron(&i, str, tab);
			else if (str[i] == '<' || str[i] == ';' || str[i] == '|')
				ft_other_case(&i, str, tab);
		}
	}
	return (tab);
}
