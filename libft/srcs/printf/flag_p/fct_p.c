/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:56:47 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/04 14:10:14 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			fct_p(va_list *ap, t_opt *opt)
{
	unsigned long	add;
	int				i;

	i = 0;
	p_check_wildcard(ap, opt);
	add = va_arg(*ap, unsigned long);
	if (!(opt->str = convert_hex(add, "0123456789abcdef", 16)))
		return (0);
	if (opt->tiret)
		opt->str = p_tiret(opt->str, opt->tiret);
	else if (opt->nbr)
		opt->str = p_nbr(opt->str, opt->nbr);
	else if (!(opt->str = p_0x(opt->str)))
		return (0);
	if (opt->str == NULL)
		return (0);
	return (opt->len = opt->len + ft_strlen(opt->str));
}
