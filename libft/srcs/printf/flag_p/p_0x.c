/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_0x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:09:05 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/04 14:10:28 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*p_0x(char *s)
{
	char	*s2;
	int		i;
	int		j;

	i = 2;
	j = 0;
	if (!(s2 = malloc(sizeof(char) * (ft_strlen(s) + 3))))
		return (NULL);
	s2[0] = '0';
	s2[1] = 'x';
	while (s[j])
		s2[i++] = s[j++];
	s2[i] = 0;
	free(s);
	return (s2);
}
