/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_nbr_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 20:04:32 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/04 12:19:11 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		idn_nbr_point(t_opt *opt, char *s, int len_str, int len_s)
{
	int		i;
	int		nb;

	i = 0;
	if (!(opt->str = ft_calloc((len_str + 1), 1)))
		return (0);
	nb = (len_s > opt->point) ?
	(opt->nbr - len_s) : (opt->nbr - opt->point - 1);
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

int				id_nbr_point(t_opt *opt, char *s)
{
	int		i;
	int		len_s;
	int		len_str;

	if (*s == '0' && opt->point == -2)
		return (opt->len = ft_strlen(id_chaine_vide(opt)));
	len_s = ft_strlen(s);
	len_str = (opt->nbr >= opt->point) ? opt->nbr : opt->point;
	len_str = (len_s > len_str) ? len_s : len_str;
	if (*s == '-')
		return (opt->len = idn_nbr_point(opt, s, len_str + 1, len_s));
	i = 0;
	if (!(opt->str = ft_calloc(len_str + 1, 1)))
		return (0);
	opt->point = (len_s > opt->point) ? len_s : opt->point;
	if (len_str != len_s)
	{
		while (i < (opt->nbr - opt->point))
			opt->str[i++] = ' ';
		while (opt->point-- > len_s)
			opt->str[i++] = '0';
	}
	ft_strcpy(opt->str + i, s);
	free(s);
	return (opt->len = len_str);
}
