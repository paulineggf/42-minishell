/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_nbr_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:26:29 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/04 12:18:57 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		u_nbr_point(t_opt *opt, char *s)
{
	int		i;
	int		len_s;
	int		len_str;

	if (*s == '0' && opt->point == -2)
		return (opt->len = ft_strlen(u_chaine_vide(opt)));
	len_s = ft_strlen(s);
	len_str = (opt->nbr >= opt->point) ? opt->nbr : opt->point;
	len_str = (len_s > len_str) ? len_s : len_str;
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
