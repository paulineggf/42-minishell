/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:19:14 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/19 15:15:53 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_exit(t_parsing *tmp, t_data *data)
{
	if (tmp->arg[1] == NULL)
		exit_failure2(0, data);
	else if (tmp->arg[1] && tmp->arg[2] == NULL)
	{
		exit_failure2((unsigned char)ft_atoi(tmp->arg[1]), data);
	}
	else if (tmp->arg[2])
	{
		ft_putstr_fd("popo & max: exit: too many arguments\n", 2);
		return (1);
	}
	return (1);
}
