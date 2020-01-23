/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:03:10 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/02 22:10:15 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_atoi_printf(char *s, int *i, char c)
{
	long	res;

	res = 0;
	if (s[*i] == '*')
	{
		(*i)++;
		return (-1);
	}
	while (s[*i] && ft_isspace(s[*i]))
		(*i)++;
	while (s[*i] == '+')
		(*i)++;
	while (s[*i] && ft_isdigit(s[*i]))
	{
		res = res * 10 + (s[*i] - 48);
		(*i)++;
	}
	if (c == '.' && res == 0)
		return (-2);
	return (res);
}
