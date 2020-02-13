/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:33:30 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/13 15:35:24 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strpbrk(const char *s1, const char *s2)
{
	while (*s1)
		if (ft_strchr(s2, *s1++))
			return (char*)--s1;
	return (0);
}
