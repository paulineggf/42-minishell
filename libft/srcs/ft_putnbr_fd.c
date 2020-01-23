/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:23:58 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/14 17:14:50 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	res;
	int		div;

	nb = n;
	div = 1;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	while (nb / div >= 10)
		div = div * 10;
	while (div > 0)
	{
		res = ((nb / div) % 10) + 48;
		write(fd, &res, 1);
		div = div / 10;
	}
}
