/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:28:36 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/24 11:21:30 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *h, const char *n)
{
	int		i;
	int		j;

	i = 0;
	if (n[i] == '\0')
		return ((char*)h);
	while (h[i])
	{
		j = 0;
		while (h[i + j] == n[j])
		{
			if (n[j + 1] == '\0')
				return ((char*)(h + i));
			j++;
		}
		i++;
	}
	return (0);
}
