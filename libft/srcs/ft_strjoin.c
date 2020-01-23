/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:52:42 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/24 11:36:01 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	s3 = NULL;
	if (!s1 && !s2)
		return (NULL);
	else if (s1 && s2)
	{
		if (!(s3 = (char*)malloc(sizeof(char) *
			(ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		s3 = ft_strcpy(s3, s1);
		s3 = ft_strcat(s3, s2);
	}
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else
		return (ft_strdup(s2));
	return (s3);
}
