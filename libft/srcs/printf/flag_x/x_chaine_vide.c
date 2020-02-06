/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_chaine_vide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:12:27 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/04 11:11:05 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*x_chaine_vide(t_opt *opt)
{
	int nb;

	nb = 0;
	if (opt->zero > 0)
		nb = opt->zero;
	else if (opt->tiret > 0)
		nb = opt->tiret;
	else if (opt->nbr > 0)
		nb = opt->nbr;
	if (!(opt->str = malloc(sizeof(char) * (nb + 1))))
		return (NULL);
	opt->str = ft_memset(opt->str, ' ', nb);
	opt->str[nb] = 0;
	return (opt->str);
}
