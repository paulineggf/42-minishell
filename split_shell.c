/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:19:45 by mcraipea          #+#    #+#             */
/*   Updated: 2020/01/28 18:01:54 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			ft_error(int flag_double, int flag_simple)
{
	if (flag_double == 1)
		ft_putstr("Il manque un double chevron.\n");
	else if (flag_simple == 1)
		ft_putstr("Il manque un simple chevron.\n");
}

static void		ft_new_line(char *buf, char **tab)
{
	int			i;
	int			j;
	int			size_line;

	i = 0;
	j = 0;
	size_line = ft_strlen(buf);
	while (tab[i])
		i++;
	tab[i] = malloc(sizeof(char) * size_line + 1);
	while (buf[j])
	{
		tab[i][j] = buf[j];
		j++;
	}
	tab[i][j] = '\0';
}

char		**split_shell(char *str)
{
	int			i;
	int			j;
	int			flag_simple;
	int			flag_double;
	char		buf[256];
	char		**tab;

	i = 0;
	j = 0;
	flag_simple = 0;
	flag_double = 0;
	tab = ft_calloc(sizeof(char*) * 128, 1);
	ft_bzero(buf, 256);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '"' || str[i] == '\'')
		{
			if (str[i++] == '"')
			{
				flag_double = 1;
				ft_bzero(buf, 256);
				j = 0;
				while (str[i] && str[i] != '"')
					buf[j++] = str[i++];                   //si un " est trouve
				if (str[i++] == '"')
				{
					flag_double = 0;
					ft_new_line(buf, tab);
				}
				else												//les erreurs ne sont pas bonnes
				{
					ft_error(flag_double, flag_simple);
					return (NULL);
				}

			}
			else
			{
				flag_simple = 1;
				ft_bzero(buf, 256);
				j = 0;
				while (str[i] && str[i] != '\'')
					buf[j++] = str[i++];					//si un ' est trouve
				if (str[i++] == '\'')
				{
					flag_simple = 0;
					ft_new_line(buf, tab);
				}
				else
				{
					ft_error(flag_double, flag_simple);
					return (NULL);
				}
			}
		}
		else
		{
			ft_bzero(buf, 256);
			j = 0;
			while (str[i] && (str[i] != ' ' && str[i] != '>' && str[i] != '<' && str[i] != '|' && str[i] != ';'))
				buf[j++] = str[i++];
			ft_new_line(buf, tab);
			while (str[i] && str[i] == ' ')
				i++;
			if (str[i] == '>')
			{
				if (str[i + 1] == '>')             //Partie sans les "" ou ''
				{
					ft_new_line(">>", tab);
					i += 2;
				}
				else
				{
					ft_bzero(buf, 256);
					buf[0] = str[i];
					ft_new_line(buf, tab);
					i++;
				}
			}
			else if (str[i] == '<' || str[i] == ';' || str[i] == '|')
			{
				ft_bzero(buf, 256);
				buf[0] = str[i];
				ft_new_line(buf, tab);
				i++;
			}
		}
	}
	return (tab);
}
