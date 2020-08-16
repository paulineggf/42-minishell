/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:10:32 by mcraipea          #+#    #+#             */
/*   Updated: 2020/03/02 12:42:48 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_delallchar(char *str, char *c)
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

void			ft_buffer(int *i, char c, char *buf, char *str)
{
	int			k;

	k = 0;
	*i += 1;
	buf[k++] = c;
	while (str[*i] && (str[*i] != c || str[*i + 1] != ' '))
	{
		buf[k++] = str[*i];
		*i += 1;
	}
	if (str[*i])
	{
		buf[k] = c;
		*i += 1;
	}
}

char			*ft_correctif(char c, char *str, t_data *data)
{
	int			i;
	int			j;
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
			ft_buffer(&i, c, buf, str);
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

void			ft_verif_arg(char **tab, t_data *data)
{
	if (!ft_strcmp(tab[0], ";"))
		exit_failure(
		"popo & max: syntax error near unexpected token `;'\n", data);
}
