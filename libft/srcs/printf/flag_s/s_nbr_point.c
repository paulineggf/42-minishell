/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_nbr_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:27:27 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/05 15:11:19 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_nbr_point(t_opt *opt, char *s)
{
	int		i;
	char	*s2;
	int		len_s2;
	int		len_str;

	len_str = 0;
	if (opt->point < 0)
		opt->point = 0;
	if (!(s2 = ft_strndup(s, opt->point)))
		return (0);
	len_s2 = ft_strlen(s2);
	i = 0;
	if (!(opt->str = ft_strdup(s2)))
		return (0);
	if (opt->nbr > len_s2)
	{
		if (!(opt->str = ft_calloc(opt->nbr + 1, 1)))
			return (0);
		ft_strcpy(opt->str + opt->nbr - len_s2, s2);
	}
	while (opt->nbr-- > len_s2)
		opt->str[i++] = ' ';
	free(s2);
	return (opt->len = len_str + ft_strlen(opt->str));
}
