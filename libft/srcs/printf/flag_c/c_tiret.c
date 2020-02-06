/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_tiret.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:21:39 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/05 16:53:46 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		c_tiret(t_opt *opt, char *s)
{
	int		len_s;
	int		i;

	len_s = ft_strlen(s);
	i = len_s;
	if (!(opt->str = ft_strdup(s)))
		return (0);
	if (opt->tiret > len_s)
	{
		if (!(opt->str = ft_calloc(opt->tiret + 1, 1)))
			return (0);
		ft_strcpy(opt->str, s);
	}
	if (len_s == 0)
	{
		write(1, NULL, 1);
		len_s++;
		opt->len++;
	}
	while (opt->tiret-- > len_s)
		opt->str[i++] = ' ';
	return (opt->len = opt->len + ft_strlen(opt->str));
}
