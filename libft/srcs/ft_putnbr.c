/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:24:06 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/24 11:16:41 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void			ft_putnbr(int n)
{
	long	nb;
	int		div;

	nb = n;
	div = 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	while (nb / div >= 10)
		div = div * 10;
	while (div > 0)
	{
		ft_putchar(((nb / div) % 10) + 48);
		div = div / 10;
	}
}
