/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:46:38 by mcraipea          #+#    #+#             */
/*   Updated: 2020/01/30 18:43:53 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			main(int argc, char **argv, char **env)
{
	t_data		*data;

	(void)argv;
	(void)env;
	if (!(data = ft_calloc(1, sizeof(t_data))))
		return (0);
	data->env = env;
	garbage_init(data);
	if (argc == 1)
		main_function(data);
	return (0);
}
