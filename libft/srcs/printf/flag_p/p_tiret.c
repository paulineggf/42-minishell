/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_tiret.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:04:14 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/04 14:05:57 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*p_tiret(char *s, int nb)
{
	char	*s2;
	int		i;
	int		j;
	int		len_s;

	i = 2;
	j = 0;
	if (nb < 0)
		nb = 0;
	len_s = ft_strlen(s);
	if (!(s2 = malloc(sizeof(char) * (len_s + 2 + nb))))
		return (NULL);
	s2[0] = '0';
	s2[1] = 'x';
	while (s[j])
		s2[i++] = s[j++];
	while (i < nb)
		s2[i++] = ' ';
	s2[i] = 0;
	free(s);
	return (s2);
}
