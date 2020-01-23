/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:09:26 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/04 12:19:36 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	idn_zero(t_opt *opt, char *s, int len_s)
{
	int		i;

	i = 0;
	if (opt->zero > len_s - 1)
	{
		if (!(opt->str = ft_calloc(opt->zero + 2, 1)))
			return (0);
		opt->str[i++] = '-';
		ft_strcpy(opt->str + (opt->zero - len_s + 1), s + 1);
	}
	else
	{
		if (!(opt->str = ft_strdup(s)))
			return (0);
	}
	while (opt->zero > len_s)
	{
		opt->str[i++] = '0';
		opt->zero--;
	}
	free(s);
	return (opt->len = ft_strlen(opt->str));
}

int			id_zero(t_opt *opt, char *s)
{
	int		i;
	int		len_s;

	if ((len_s = ft_strlen(s)) && *s == '0' && opt->zero == -2)
		return (opt->len = ft_strlen(id_chaine_vide(opt)));
	i = 0;
	if (*s == '-')
		return (idn_zero(opt, s, len_s));
	if (opt->zero > len_s)
	{
		if (!(opt->str = ft_calloc(opt->zero + 1, 1)))
			return (0);
		ft_strcpy(opt->str + opt->zero - len_s, s);
	}
	else
	{
		if (!(opt->str = ft_strdup(s)))
			return (0);
	}
	while (opt->zero-- > len_s)
		opt->str[i++] = '0';
	free(s);
	return (opt->len = ft_strlen(opt->str));
}
