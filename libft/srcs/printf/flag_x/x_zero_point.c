/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_zero_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:32:02 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/04 12:18:16 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			x_zero_point(t_opt *opt, char *s)
{
	int		i;
	int		len_s;
	int		len_str;

	if (*s == '0' && opt->point == -2)
		return (opt->len = ft_strlen(x_chaine_vide(opt)));
	len_s = ft_strlen(s);
	len_str = (opt->zero >= opt->point) ? opt->zero : opt->point;
	len_str = (len_s > len_str) ? len_s : len_str;
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
	if (opt->type == 7)
		opt->str = ft_strupcase(opt->str);
	free(s);
	return (opt->len = len_str);
}
