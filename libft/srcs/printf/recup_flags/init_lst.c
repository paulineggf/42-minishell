/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:40:21 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/06 12:36:15 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_opt	*cpy_string(char *str, int *i)
{
	t_opt	*new;
	int		j;
	int		k;

	j = *i;
	k = 0;
	while (str[*i] && str[*i] != '%')
	{
		(*i)++;
		k++;
	}
	if (*i == j)
		return (NULL);
	if (!(new = malloc(sizeof(t_opt))))
		return (NULL);
	ft_bzero(new, sizeof(t_opt));
	new->str = ft_strndup(&str[j], k);
	new->len = ft_strlen(new->str) + new->len;
	return (new);
}

static void		fill_opt(int *opt, int *wildcard, char *str, int *i)
{
	char	c;

	c = str[*i];
	if (ft_charset(str[*i], "-.0") >= 0)
		(*i)++;
	if (ft_charset(str[*i - 1], ".-") >= 0 && !ft_isdigit(str[*i]))
		*opt = -2;
	if (ft_charset(str[*i], "0123456789*") >= 0)
	{
		*opt = ft_atoi_printf(str, i, c);
		if (*opt == -1)
		{
			*opt = 0;
			*wildcard += 1;
		}
	}
}

static void		compare_flags(t_opt *new, char *str, int *i)
{
	if (str[*i] == '0')
	{
		fill_opt(&new->zero, &new->wildcard_zero, str, i);
		return ;
	}
	else if (str[*i] == '-')
	{
		fill_opt(&new->tiret, &new->wildcard_tiret, str, i);
		return ;
	}
	else if (str[*i] == '.')
	{
		fill_opt(&new->point, &new->wildcard_point, str, i);
		return ;
	}
	else if (ft_charset(str[*i], "123456789*") >= 0)
	{
		fill_opt(&new->nbr, &new->wildcard_nbr, str, i);
		return ;
	}
	(*i)++;
}

static t_opt	*cpy_opt(char *str, int *i)
{
	t_opt	*new;

	if (!(new = malloc(sizeof(t_opt))))
		return (NULL);
	ft_bzero(new, sizeof(t_opt));
	while (str[*i] && ft_charset(str[*i], "cspdiuxX%") == -1)
		compare_flags(new, str, i);
	if (ft_charset(str[*i], "cspdiuxX%") >= 0)
		new->type = match_type(str[*i]);
	(*i)++;
	return (new);
}

t_list			*init_lst(char *str)
{
	t_list	*lst;
	t_opt	*opt;
	int		i;

	i = 0;
	lst = NULL;
	while (str[i])
	{
		if ((opt = cpy_string(str, &i)))
			ft_lstadd_back(&lst, ft_lstnew(opt));
		if (str[i] == '%')
		{
			i++;
			ft_lstadd_back(&lst, ft_lstnew((void*)cpy_opt(str, &i)));
		}
	}
	free(str);
	return (lst);
}
