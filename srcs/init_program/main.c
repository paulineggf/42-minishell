/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:46:38 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/20 15:21:49 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			main(int argc, char **argv, char **env)
{
	t_data		*data;

	if (argc == 1)
	{
		if (!(data = ft_calloc(1, sizeof(t_data))))
			return (1);
		data->env = ft_init_env(env, data);
		garbage_init(data);
		main_function(data);
	}
	else
		ft_printf(2, "popo & max: %s: No such file or directory\n", argv[1]);
	return (0);
}
