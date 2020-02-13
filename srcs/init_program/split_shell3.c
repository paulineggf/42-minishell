/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:54:55 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/13 19:10:48 by mcraipea         ###   ########.fr       */
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

void			ft_del_slash(int *i, int *j, char *str, char *buf)
{
	int			size;

	size = ft_strlen(str);
	if (str[*i] == '\\')
	{
		if (*i < size && str[*i + 1] == '\\')
		{
			*i += 1;
			buf[*j] = str[*i];
			*j += 1;
			*i += 1;
		}
		else
			*i += 1;
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

void		ft_delallchar(char *str, char *c)
{
	while ((str = strpbrk(str, c)) != NULL)
	{
		ft_memmove(str, str + 1, strlen(str));
	}
}

void			ft_del_quote2(char c, char *buf, t_data *data)
{
	int			i;
	int			j;
	int			quote;

	(void)data;
	i = 0;
	quote = 0;
	while (buf[i])
	{
		if (buf[i++] == c)
			quote++;
	}
	i = 0;
	j = 0;
	if (quote > 2 && quote % 2 == 0)
	{
		if (c == '"')
			ft_delallchar(buf, "\"");
		else if (c == '\'')
			ft_delallchar(buf, "\'");
	}
}

// void			ft_buffer(int *i, char c, char *buf, char *str)
// {
// 	int			k;

// 	k = 0;
// 	*i += 1;
// 	buf[k++] = c;
// 	while (str[*i] && (str[*i] != c || str[*i + 1] != ' '))
// 		buf[k++] = str[*i++];
// 	if (str[*i])
// 	{
// 		buf[k] = c;
// 		*i += 1;
// 	}
// }

char			*ft_correctif(char c, char *str, t_data *data)
{
	int			i;
	int			j;
	int			k;
	int			size;
	char		*buf;
	char		*dest;

	size = ft_strlen(str) + 1;
	easy_malloc((void**)&dest, sizeof(char) * size, data);
	easy_malloc((void**)&buf, sizeof(char) * size, data);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
		 	k = 0;
		 	i += 1;
		 	buf[k++] = c;
		 	while (str[i] && (str[i] != c || str[i + 1] != ' '))
		 		buf[k++] = str[i++];
			if (str[i])
		 	{
		 		buf[k] = c;
		 		i += 1;
		 	}
			//ft_buffer(&i, c, buf, str);
			ft_del_quote2(c, buf, data);
			j += ft_strlen(buf);
			ft_strcat(dest, buf);
			ft_bzero(buf, size);
		}
		else
			dest[j++] = str[i++];
	}
	return (dest);
}
