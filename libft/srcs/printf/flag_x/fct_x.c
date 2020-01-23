/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:58:13 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/04 12:08:39 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			fct_x(va_list *ap, t_opt *opt)
{
	char			*s;

	x_check_wildcard(ap, opt);
	if (!(s = convert_hex(va_arg(*ap, unsigned int), "0123456789abcdef", 16)))
		return (0);
	if (opt->point && opt->tiret == 0 && opt->zero == 0 && opt->nbr == 0)
		return (x_point(opt, s));
	if (opt->tiret && !opt->point)
		return (x_tiret(opt, s));
	if (opt->nbr && opt->point)
		return (x_nbr_point(opt, s));
	if (opt->nbr)
		return (x_nbr(opt, s));
	if (opt->zero && !opt->point)
		return (x_zero(opt, s));
	if (opt->tiret && opt->point)
		return (x_tiret_point(opt, s));
	if (opt->zero && opt->point)
		return (x_zero_point(opt, s));
	if (!(opt->str = ft_strdup(s)))
		return (0);
	if (opt->type == 7)
		opt->str = ft_strupcase(opt->str);
	free(s);
	return (opt->len = opt->len + ft_strlen(opt->str));
}
