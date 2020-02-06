/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:28:01 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/14 19:26:33 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (n[i] == '\0')
		return ((char*)h);
	while (h[i] && i < len)
	{
		j = 0;
		while (h[i + j] == n[j] && i + j < len)
		{
			if (n[j + 1] == '\0')
				return ((char*)(h + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
