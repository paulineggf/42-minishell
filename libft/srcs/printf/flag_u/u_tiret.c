/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_tiret.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:27:34 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/03 21:29:25 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		u_tiret(t_opt *opt, char *s)
{
	int		i;
	int		len_s;

	len_s = ft_strlen(s);
	if (opt->tiret > len_s)
	{
		if (!(opt->str = ft_calloc(opt->tiret + 1, 1)))
			return (0);
		ft_strcpy(opt->str, s);
	}
	else
	{
		if (!(opt->str = ft_strdup(s)))
			return (0);
	}
	i = len_s;
	while (opt->tiret > len_s)
	{
		opt->str[i++] = ' ';
		opt->tiret--;
	}
	free(s);
	return (opt->len = ft_strlen(opt->str));
}
