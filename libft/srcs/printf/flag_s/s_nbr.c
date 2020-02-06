/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_nbr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:16:21 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/05 16:01:16 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_nbr(t_opt *opt, char *s)
{
	int		len_s;
	int		len_str;
	int		i;

	len_s = ft_strlen(s);
	len_str = 0;
	i = 0;
	if (!(opt->str = ft_strdup(s)))
		return (s_free(s));
	if (opt->nbr > len_s)
	{
		if (!(opt->str = ft_calloc(opt->nbr + 1, 1)))
			return (0);
		ft_strcpy(opt->str + opt->nbr - len_s, s);
	}
	while (opt->nbr-- > len_s)
		opt->str[i++] = ' ';
	if (len_s == 0)
	{
		len_str++;
		write(1, NULL, 1);
	}
	return (opt->len = len_str + ft_strlen(opt->str));
}
