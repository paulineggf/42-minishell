/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourc_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:35:31 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/05 18:40:26 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pourc_nbr(t_opt *opt, char *s)
{
	int		len_s;
	int		i;
	int		j;

	if (*s == '0' && opt->nbr == -2)
		return (opt->len = ft_strlen(c_chaine_vide(opt)));
	len_s = ft_strlen(s);
	i = 0;
	j = 0;
	if (!(opt->str = ft_strdup(s)))
		return (0);
	if (opt->nbr > len_s)
	{
		if (!(opt->str = ft_calloc(opt->nbr + 1, 1)))
			return (0);
		ft_strcpy(opt->str + opt->nbr - len_s, s);
	}
	opt->len = (len_s == 0) ? 1 : 0;
	if (opt->len == 1)
		len_s++;
	while (opt->nbr-- > len_s)
		opt->str[i++] = ' ';
	if (opt->len == 1)
		write(1, NULL, 1);
	return (opt->len = opt->len + ft_strlen(opt->str));
}
