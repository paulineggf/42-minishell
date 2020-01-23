/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:23:09 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/24 11:16:08 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memrchr(const void *s, int c, size_t n)
{
	while (n && *((unsigned char*)(s + n)) != c)
		n--;
	if (n == 0 && *((unsigned char*)(s + n)) != c)
		return (NULL);
	return ((unsigned char*)(s + n));
}
