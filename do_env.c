/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:51:34 by mcraipea          #+#    #+#             */
/*   Updated: 2020/01/23 16:22:21 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		do_env(char *line, char **env)
{
	int			i;

	i = 0;
	//aller voir dans data qu'il n'y a pas d'arguments ou d'options
	while (env[i])
	{
		ft_putstr(env[i++]);
		ft_putstr("\n");
	}
}
