/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_pourcentage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:24:17 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/06 12:55:19 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fct_pourcentage(va_list *ap, t_opt *opt)
{
	int		c;
	char	*s;

	pourc_check_wildcard(ap, opt);
	c = 37;
	s = (char*)&c;
	if (opt->tiret)
		return (pourc_tiret(opt, s));
	if (opt->nbr)
		return (pourc_nbr(opt, s));
	if (opt->zero)
		return (pourc_zero(opt, s));
	if (!(opt->str = ft_calloc((1 + 1), 1)))
		return (0);
	if (c == 0)
		opt->len += 1;
	opt->str[0] = c;
	return (opt->len = opt->len + ft_strlen(opt->str));
}
