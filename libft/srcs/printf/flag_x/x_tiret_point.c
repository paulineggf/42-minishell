/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_tiret_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:30:45 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/04 12:15:56 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			x_tiret_point(t_opt *opt, char *s)
{
	int		i;
	int		len_s;
	int		len_str;

	if (*s == '0' && opt->point == -2)
		return (opt->len = ft_strlen(x_chaine_vide(opt)));
	i = 0;
	len_s = ft_strlen(s);
	len_str = (opt->point >= opt->tiret) ? opt->point : opt->tiret;
	len_str = (len_s > len_str) ? len_s : len_str;
	if (!(opt->str = ft_calloc(len_str + 1, 1)))
		return (0);
	while (opt->point > len_s)
	{
		opt->str[i++] = '0';
		opt->point--;
	}
	ft_strcpy(opt->str + i, s);
	i = len_s + i;
	while (i < len_str)
		opt->str[i++] = ' ';
	if (opt->type == 7)
		opt->str = ft_strupcase(opt->str);
	free(s);
	return (opt->len = ft_strlen(opt->str));
}
