/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_tiret_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:28:16 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/05 16:03:49 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_tiret_point(t_opt *opt, char *s)
{
	int		i;
	char	*s2;
	int		len_s2;

	if (opt->tiret == -2 || opt->point == -2)
		return (opt->len = ft_strlen(s_chaine_vide(opt)));
	if (!(s2 = ft_strndup(s, opt->point)))
		return (0);
	len_s2 = ft_strlen(s2);
	if (!(opt->str = ft_strdup(s2)))
		return (0);
	if (opt->tiret > len_s2)
	{
		if (!(opt->str = ft_calloc(opt->tiret + 1, 1)))
			return (0);
		ft_strcpy(opt->str, s2);
	}
	i = len_s2;
	while (opt->tiret-- > len_s2)
		opt->str[i++] = ' ';
	free(s2);
	return (opt->len = ft_strlen(opt->str));
}
