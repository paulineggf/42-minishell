/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourc_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:48:24 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/05 18:50:58 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pourc_zero(t_opt *opt, char *s)
{
	int		i;
	int		len_s;

	if ((len_s = ft_strlen(s)) && *s == '0' && opt->zero == -2)
		return (opt->len = ft_strlen(u_chaine_vide(opt)));
	i = 0;
	if (opt->zero > len_s)
	{
		if (!(opt->str = ft_calloc(opt->zero + 1, 1)))
			return (0);
		ft_strcpy(opt->str + opt->zero - len_s, s);
	}
	else
	{
		if (!(opt->str = ft_strdup(s)))
			return (0);
	}
	while (opt->zero-- > len_s)
		opt->str[i++] = '0';
	return (opt->len = ft_strlen(opt->str));
}
