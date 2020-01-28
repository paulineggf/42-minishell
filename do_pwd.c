/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:54:38 by mcraipea          #+#    #+#             */
/*   Updated: 2020/01/23 16:25:39 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		do_pwd()
{
	char	*repertoire;

	if (!(getcwd(repertoire, 4096)))
		return ;
	ft_putstr(repertoire);
	ft_putstr("\n");
}
