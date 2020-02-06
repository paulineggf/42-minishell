/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:57:50 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/04 11:42:56 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fct_id(va_list *ap, t_opt *opt)
{
	int		d;
	char	*s;

	id_check_wildcard(ap, opt);
	d = va_arg(*ap, int);
	if (!((s = ft_itoa(d))))
		return (0);
	if (opt->point && opt->tiret == 0 && opt->zero == 0 && opt->nbr == 0)
		return (id_point(opt, s));
	if (opt->tiret && !opt->point)
		return (id_tiret(opt, s));
	if (opt->nbr && opt->point)
		return (id_nbr_point(opt, s));
	if (opt->nbr)
		return (id_nbr(opt, s));
	if (opt->zero && !opt->point)
		return (id_zero(opt, s));
	if (opt->tiret && opt->point)
		return (id_tiret_point(opt, s));
	if (opt->zero && opt->point)
		return (id_zero_point(opt, s));
	if (!(opt->str = ft_strdup(s)))
		return (0);
	free(s);
	return (opt->len = opt->len + ft_strlen(opt->str));
}
