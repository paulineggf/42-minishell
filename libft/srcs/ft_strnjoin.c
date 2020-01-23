/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:35:55 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/02 17:40:19 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*s3;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 || !(s3 = malloc(sizeof(char) * (ft_strlen(s1) + n + 1))))
	{
		free(s1);
		return (NULL);
	}
	while (s1[++i])
		s3[i] = s1[i];
	while (j < n && s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	free(s1);
	return (s3);
}
