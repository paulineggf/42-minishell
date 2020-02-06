/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:58:02 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/04 11:43:32 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fct_u(va_list *ap, t_opt *opt)
{
	unsigned int	d;
	char			*s;

	u_check_wildcard(ap, opt);
	d = va_arg(*ap, unsigned int);
	if (!(s = ft_uitoa(d)))
		return (0);
	if (opt->point && opt->tiret == 0 && opt->zero == 0 && opt->nbr == 0)
		return (u_point(opt, s));
	if (opt->tiret && !opt->point)
		return (u_tiret(opt, s));
	if (opt->nbr && opt->point)
		return (u_nbr_point(opt, s));
	if (opt->nbr)
		return (u_nbr(opt, s));
	if (opt->zero && !opt->point)
		return (u_zero(opt, s));
	if (opt->tiret && opt->point)
		return (u_tiret_point(opt, s));
	if (opt->zero && opt->point)
		return (u_zero_point(opt, s));
	if (!(opt->str = ft_strdup(s)))
		return (0);
	free(s);
	return (opt->len = ft_strlen(opt->str));
}
