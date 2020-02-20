/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:19:14 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/20 15:39:12 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_atoi_minishell(char *s, t_data *data)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	if (!ft_isdigit(s[i]))
		exit_failure2(255, s, "numeric argument required\n", data);
	while (s[i] && ft_isdigit(s[i]))
	{
		res = res * 10 + (s[i] - 48);
		i++;
	}
	if (s[i] != '\0')
		exit_failure2(255, s, "numeric argument required\n", data);
	return (res * sign);
}

int			ft_exit(t_parsing *tmp, t_data *data)
{
	int		ret;

	if (tmp->arg[1] == NULL)
		exit_failure2(0, NULL, NULL, data);
	ret = ft_atoi_minishell(tmp->arg[1], data);
	if (tmp->arg[1] && tmp->arg[2] == NULL)
		exit_failure2((unsigned char)ret, NULL, NULL, data);
	else if (tmp->arg[2])
	{
		ft_putstr_fd("exit\npopo & max: exit: too many arguments\n", 2);
		data->ret = 1;
		return (1);
	}
	return (1);
}
