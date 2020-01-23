/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:40:37 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/05 17:19:40 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fct_c(va_list *ap, t_opt *opt)
{
	int		c;
	char	*s;

	c_check_wildcard(ap, opt);
	c = va_arg(*ap, int);
	s = (char*)&c;
	if (opt->tiret)
		return (c_tiret(opt, s));
	if (opt->nbr)
		return (c_nbr(opt, s));
	if (!(opt->str = ft_calloc((1 + 1), 1)))
		return (0);
	if (c == 0)
		opt->len += 1;
	opt->str[0] = c;
	return (opt->len = opt->len + ft_strlen(opt->str));
}
