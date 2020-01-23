/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_zero_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:06:10 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/05 21:07:57 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	idn_zero_point(t_opt *opt, char *s, int len_str, int len_s)
{
	int		i;
	int		nb;

	i = 0;
	if (!(opt->str = ft_calloc((len_str + 1), 1)))
		return (0);
	nb = (len_s > opt->point) ?
	(opt->zero - len_s) : (opt->zero - opt->point - 1);
	if (len_str != len_s)
	{
		while (i < nb)
			opt->str[i++] = ' ';
		opt->str[i++] = '-';
		while (opt->point > len_s - 1)
		{
			opt->str[i++] = '0';
			opt->point--;
		}
	}
	ft_strcpy(opt->str + i, s + 1);
	free(s);
	return (opt->len = ft_strlen(opt->str));
}

int			id_zero_point(t_opt *opt, char *s)
{
	int		i;
	int		len_s;
	int		len_str;

	if (*s == '0' && opt->point == -2)
		return (opt->len = ft_strlen(id_chaine_vide(opt)));
	len_s = ft_strlen(s);
	len_str = (opt->zero >= opt->point) ? opt->zero : opt->point;
	len_str = (len_s > len_str) ? len_s : len_str;
	if (*s == '-')
		return (opt->len = idn_zero_point(opt, s, len_str + 1, len_s));
	i = 0;
	if (!(opt->str = ft_calloc(len_str + 1, 1)))
		return (0);
	opt->point = (len_s > opt->point) ? len_s : opt->point;
	if (len_str != len_s)
	{
		while (i < (opt->zero - opt->point))
			opt->str[i++] = ' ';
		while (opt->point-- > len_s)
			opt->str[i++] = '0';
	}
	ft_strcpy(opt->str + i, s);
	free(s);
	return (opt->len = len_str);
}
