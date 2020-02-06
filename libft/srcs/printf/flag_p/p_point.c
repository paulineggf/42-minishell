/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_point.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:58:45 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/04 14:01:37 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*p_point(char *s, int nb)
{
	char	*s2;
	int		i;
	int		j;
	int		len_s;

	i = 2;
	j = 0;
	len_s = ft_strlen(s);
	if (!(s2 = ft_calloc((len_s + 3), 1)))
		return (NULL);
	if (nb > (len_s - 1))
		if (!(s2 = ft_calloc((3 + nb), 1)))
			return (NULL);
	s2[0] = '0';
	s2[1] = 'x';
	while ((i - 2) < (nb - len_s))
		s2[i++] = '0';
	while (s[j])
		s2[i++] = s[j++];
	free(s);
	return (s2);
}
