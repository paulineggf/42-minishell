/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:36:06 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/28 18:39:35 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_uitoa_bis(int count, int div, long nb)
{
	char	*s;
	long	res;
	int		i;

	res = 0;
	i = 0;
	if (!(s = malloc(sizeof(char) * (count + 2))))
		return (NULL);
	while (div > 0)
	{
		res = (nb / div) % 10;
		s[i++] = res + 48;
		div = div / 10;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_uitoa(unsigned int n)
{
	int				div;
	int				count;

	div = 1;
	count = 0;
	while (n / div >= 10)
	{
		div = div * 10;
		count++;
	}
	return (ft_uitoa_bis(count, div, n));
}
