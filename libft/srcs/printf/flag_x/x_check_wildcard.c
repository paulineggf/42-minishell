/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_check_wildcard.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:36:58 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/06 15:42:33 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		boucle_wildcard(va_list *ap, t_opt *opt)
{
	while (opt->wildcard_tiret > 0)
	{
		opt->tiret = va_arg(*ap, int);
		if (opt->tiret < 0)
			opt->tiret *= -1;
		opt->wildcard_tiret--;
	}
	while (opt->wildcard_point > 0)
	{
		opt->point = va_arg(*ap, int);
		if (opt->point < 0)
			opt->point = 0;
		opt->wildcard_point--;
	}
}

void			x_check_wildcard(va_list *ap, t_opt *opt)
{
	while (opt->wildcard_zero > 0)
	{
		opt->zero = va_arg(*ap, int);
		if (opt->zero < 0)
		{
			opt->tiret = opt->zero * -1;
			opt->zero = 0;
		}
		opt->wildcard_zero--;
	}
	while (opt->wildcard_nbr > 0)
	{
		opt->nbr = va_arg(*ap, int);
		if (opt->nbr < 0)
		{
			opt->tiret = opt->nbr * -1;
			opt->nbr = 0;
		}
		opt->wildcard_nbr--;
	}
	boucle_wildcard(ap, opt);
}
