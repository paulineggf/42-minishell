/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:55:14 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/24 19:10:45 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_new_line(char *buf, char **tab, t_data *data)
{
	int			i;
	int			j;
	int			size_line;

	i = 0;
	j = 0;
	size_line = ft_strlen(buf);
	while (tab[i])
		i++;
	easy_malloc((void**)&tab[i], sizeof(char) * (size_line + 1), data);
	while (buf[j])
	{
		tab[i][j] = buf[j];
		j++;
	}
	tab[i][j] = '\0';
}

void			ft_simple_quote(int *i, char *str, char **tab, t_data *data)
{
	int			j;
	char		*buf;

	easy_malloc((void**)&buf, sizeof(char) * 256, data);
	j = 0;
	*i += 1;
	while (str[*i] && str[*i] != '\'')
	{
		buf[j++] = str[*i];
		*i += 1;
	}
	if (str[*i] == '\'')
	{
		*i += 1;
		ft_new_line(buf, tab, data);
	}
	else
		ft_error(0, 1, data);
}

void			ft_double_quote(int *i, char *str, char **tab, t_data *data)
{
	int			j;
	char		*buf;

	easy_malloc((void**)&buf, sizeof(char) * 256, data);
	j = 0;
	*i += 1;
	while (str[*i] && str[*i] != '"')
	{
		buf[j++] = str[*i];
		*i += 1;
	}
	if (str[*i] == '"')
	{
		*i += 1;
		buf = control_env(buf, data);
		ft_new_line(buf, tab, data);
	}
	else
		ft_error(1, 0, data);
}

void			ft_line_basic(int *i, char *str, char **tab, t_data *data)
{
	int			j;
	char		*buf;

	easy_malloc((void**)&buf, sizeof(char) * 256, data);
	j = 0;
	while (str[*i] && (str[*i] != ' ' && str[*i] != '>'
		&& str[*i] != '<' && str[*i] != '|' && str[*i] != ';'
		&& str[*i] != '"' && str[*i] != '\''))
	{
		ft_del_slash(i, &j, str, buf);
		*i += 1;
	}
	if (str[*i] == '\'' && !(ft_simple_quote2(i, &j, str, buf)))
		ft_error(0, 1, data);
	if (str[*i] == '"' && !(ft_double_quote2(i, &j, str, buf)))
		ft_error(1, 0, data);
	buf = control_env(buf, data);
	if (buf[0] != '\0')
		ft_new_line(buf, tab, data);
	while (str[*i] && str[*i] == ' ')
		*i += 1;
}

void			ft_chevron(int *i, char *str, char **tab, t_data *data)
{
	if (str[*i + 1] == '>')
	{
		ft_new_line(">>", tab, data);
		*i += 2;
	}
	else
	{
		ft_new_line(">", tab, data);
		*i += 1;
	}
}
