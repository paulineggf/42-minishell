/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:53:52 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/28 12:48:39 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	char	*var;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(var = malloc(sizeof(char) * (count * size))))
		return (NULL);
	ft_bzero((void*)var, count * size);
	return ((void*)var);
}
