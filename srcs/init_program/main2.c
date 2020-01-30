/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:34:48 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/30 14:39:40 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv)
{	
	t_data		*data;

	(void)argc;
	(void)argv;
	if (!(data = ft_calloc(1, sizeof(t_data))))
		return (0);
	garbage_init(data);
	data->lst_parsing = NULL;
	data->lst_parsing = parsing_command("list1 ; list2 ; list3", data);
	ft_lstclear(&data->garbage_collector, &free);
	return (0);
}
