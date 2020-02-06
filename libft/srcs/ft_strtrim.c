/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:28:48 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/24 11:41:07 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len_s1;
	char	*s2;

	i = 0;
	len_s1 = ft_strlen(s1) - 1;
	if (!set)
		return (ft_strdup(s1));
	if (!s1)
		return (NULL);
	while (s1[i] && ft_charset(s1[i], set) >= 0)
		i++;
	if (!s1[i])
	{
		if (!(s2 = ft_strndup("", 0)))
			return (NULL);
		return (s2);
	}
	while (ft_charset(s1[len_s1], set) >= 0)
		len_s1--;
	if (!(s2 = ft_strndup((s1 + i), ft_strlen(s1) -
		(ft_strlen(s1) - len_s1 - 1) - i)))
		return (NULL);
	return (s2);
}
