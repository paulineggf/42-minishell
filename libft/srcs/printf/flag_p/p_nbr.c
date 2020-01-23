/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_nbr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:06:46 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/04 14:08:23 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*p_nbr(char *s, int nb)
{
	char	*s2;
	int		i;
	int		j;
	int		len_s;

	i = 0;
	j = 0;
	len_s = ft_strlen(s);
	if (!(s2 = ft_calloc((len_s + 3), 1)))
		return (NULL);
	if (nb > (len_s - 1))
		if (!(s2 = ft_calloc((3 + nb), 1)))
			return (NULL);
	while (i < (nb - (len_s + 2)))
		s2[i++] = ' ';
	s2[i++] = '0';
	s2[i++] = 'x';
	while (s[j])
		s2[i++] = s[j++];
	free(s);
	return (s2);
}
