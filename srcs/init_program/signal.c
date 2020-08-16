/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:54:55 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/25 12:29:00 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		minishell_signals_handler(int i)
{
	if (i == SIGINT)
	{
		ft_printf(2, "\b\b%c%c\n", 0x7f, 0x7f);
		close(0);
		signal(SIGINT, minishell_signals_handler);
		signal(SIGQUIT, minishell_signals_handler);
	}
	else if (i == SIGQUIT)
	{
		ft_printf(2, "\b\b%c%c\b\b", 0x7f, 0x7f);
		signal(SIGINT, minishell_signals_handler);
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
	int			pid;
	int			status;

	pid = 0;
	if (i == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		signal(SIGINT, minishell_signals_handler);
		signal(SIGQUIT, minishell_signals_handler);
	}
	else if (i == SIGQUIT)
	{
		waitpid(pid, &status, 0);
		ft_printf(2, "Quit: %d\n", status);
		signal(SIGQUIT, minishell_signals_handler);
		signal(SIGINT, minishell_signals_handler);
	}
}

void			minishell_signals2(void)
{
	signal(SIGQUIT, minishell_signals_handler2);
	signal(SIGINT, minishell_signals_handler2);
}
