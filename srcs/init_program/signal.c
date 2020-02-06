/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:54:55 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/06 17:55:22 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		minishell_signals_handler(int i)
{
	t_data		*data;

	if (!(data = ft_calloc(1, sizeof(t_data))))
		return ;
	if (i == SIGINT)
	{
		ft_printf("\b\b%c%c\n", 0x7f, 0x7f);
		if ((data->str_prompt = ft_prompt(data)))
			ft_putstr(data->str_prompt);
		signal(SIGINT, minishell_signals_handler);
	}
	else if (i == SIGQUIT)
		ft_printf("\b\b%c%c\b\b", 0x7f, 0x7f);
}

void			minishell_signals(void)
{
	signal(SIGINT, minishell_signals_handler);
	signal(SIGQUIT, minishell_signals_handler);
}
