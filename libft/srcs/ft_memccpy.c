/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:21:33 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/11 16:27:23 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *((unsigned char*)(src + i)) != (unsigned char)c)
	{
		*((unsigned char*)(dest + i)) = *((unsigned char*)(src + i));
		i++;
	}
	if (i == n)
		return (NULL);
	*((unsigned char*)(dest + i)) = (unsigned char)c;
	return (dest + i + 1);
}
