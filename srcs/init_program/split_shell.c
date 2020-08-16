/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:19:45 by mcraipea          #+#    #+#             */
/*   Updated: 2020/03/02 12:43:21 by mcraipea         ###   ########.fr       */
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
	char		buf[2];

	ft_bzero(buf, 2);
	buf[0] = str[*i];
	ft_new_line(buf, tab, data);
	*i += 1;
}

int				ft_double_quote2(int *i, int *j, char *str, char *buf)
{
	*i += 1;
	while (str[*i] && str[*i] != '"')
	{
		buf[*j] = str[*i];
		*i += 1;
		*j += 1;
	}
	if (str[*i] == '"')
	{
		*i += 1;
		return (1);
	}
	else
		return (0);
}

int				ft_simple_quote2(int *i, int *j, char *str, char *buf)
{
	*i += 1;
	while (str[*i] && str[*i] != '\'')
	{
		buf[*j] = str[*i];
		*i += 1;
		*j += 1;
	}
	if (str[*i] == '\'')
	{
		*i += 1;
		return (1);
	}
	else
		return (0);
}

char			**split_shell(char *str, t_data *data)
{
	int			i;
	char		**tab;

	i = 0;
	easy_malloc((void**)&tab, sizeof(char*) * 256, data);
	str = ft_correctif('\'', str, data);
	str = ft_correctif('"', str, data);
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
	ft_verif_arg(tab, data);
	return (tab);
}
