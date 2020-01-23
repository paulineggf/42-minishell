/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_nbr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:15:21 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/04 12:09:54 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		x_nbr(t_opt *opt, char *s)
{
	int		i;
	int		len_s;

	i = 0;
	len_s = ft_strlen(s);
	if (opt->nbr > len_s)
	{
		if (!(opt->str = ft_calloc(opt->nbr + 1, 1)))
			return (0);
		ft_strcpy(opt->str + opt->nbr - len_s, s);
	}
	else
	{
		if (!(opt->str = ft_strdup(s)))
			return (0);
	}
	while (opt->nbr > len_s)
	{
		opt->str[i++] = ' ';
		opt->nbr--;
	}
	if (opt->type == 7)
		opt->str = ft_strupcase(opt->str);
	free(s);
	return (opt->len = ft_strlen(opt->str));
}
