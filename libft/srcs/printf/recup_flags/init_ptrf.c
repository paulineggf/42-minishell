/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ptrf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:16:53 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/05 18:23:10 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_ptrf(int (**f)(va_list *ap, t_opt *opt))
{
	f[0] = fct_p;
	f[1] = fct_c;
	f[2] = fct_s;
	f[3] = fct_id;
	f[4] = fct_id;
	f[5] = fct_u;
	f[6] = fct_x;
	f[7] = fct_x;
	f[8] = fct_pourcentage;
}
