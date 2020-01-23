/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_point.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:27:24 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/04 12:20:23 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		u_point(t_opt *opt, char *s)
{
	int		i;
	int		len_s;

	if ((len_s = ft_strlen(s)) && *s == '0' && opt->point == -2)
		return (opt->len = ft_strlen(u_chaine_vide(opt)));
	i = 0;
	if (opt->point > len_s)
	{
		if (!(opt->str = ft_calloc(opt->point + 1, 1)))
			return (0);
		ft_strcpy(opt->str + opt->point++ - len_s, s);
	}
	else
	{
		if (!(opt->str = ft_strdup(s)))
			return (0);
	}
	while (opt->point-- > len_s + 1)
		opt->str[i++] = '0';
	free(s);
	return (opt->len = ft_strlen(opt->str));
}
