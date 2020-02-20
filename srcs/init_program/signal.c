/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:54:55 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/20 15:22:38 by pganglof         ###   ########.fr       */
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
		ft_printf(1, "\b\b%c%c\n", 0x7f, 0x7f);
		if ((data->str_prompt = ft_prompt(data)))
			ft_putstr(data->str_prompt);
		signal(SIGINT, minishell_signals_handler);
	}
	else if (i == SIGQUIT)
	{
		ft_printf(1, "\b\b%c%c\b\b", 0x7f, 0x7f);
		signal(SIGQUIT, minishell_signals_handler);
	}
}

void			minishell_signals(void)
{
	signal(SIGQUIT, minishell_signals_handler);
	signal(SIGINT, minishell_signals_handler);
}

static void		minishell_signals_handler2(int i)
{
	t_data		*data;

	if (!(data = ft_calloc(1, sizeof(t_data))))
		return ;
	if (i == SIGINT)
	{
		ft_putstr("\n");
		signal(SIGINT, minishell_signals_handler);
		signal(SIGQUIT, minishell_signals_handler);
	}
	else if (i == SIGQUIT)
	{
		waitpid(data->pid, &data->status, 0);
		ft_printf(1, "Quit: %d\n", data->status);
		signal(SIGQUIT, minishell_signals_handler);
		signal(SIGINT, minishell_signals_handler);
	}
}

void			minishell_signals2(void)
{
	signal(SIGQUIT, minishell_signals_handler2);
	signal(SIGINT, minishell_signals_handler2);
}
