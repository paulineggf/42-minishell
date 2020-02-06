/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:22:10 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/11 16:28:30 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1)
			&& *((unsigned char*)(s1 + i)) == *((unsigned char*)(s2 + i)))
		i++;
	return (*((unsigned char*)(s1 + i)) - *((unsigned char*)(s2 + i)));
}
