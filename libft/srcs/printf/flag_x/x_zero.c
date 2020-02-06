/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_zero.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:28:52 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/04 12:16:24 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		x_zero(t_opt *opt, char *s)
{
	int		i;
	int		len_s;

	if ((len_s = ft_strlen(s)) && *s == '0' && opt->zero == -2)
		return (opt->len = ft_strlen(x_chaine_vide(opt)));
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
	if (opt->type == 7)
		opt->str = ft_strupcase(opt->str);
	free(s);
	return (opt->len = ft_strlen(opt->str));
}
