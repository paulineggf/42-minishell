/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:49:58 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/31 14:40:37 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_function(t_data *data)
{
	char		*line;

	while (1)
	{
		if ((data->str_prompt = ft_prompt(data)))
			ft_putstr(data->str_prompt);
		if (get_next_line(0, &line) == -1)
			exit_failure("get_next_line", data);
		add_garbage((void**)&line, data);
		data->lst_parsing = NULL;
		data->lst_parsing = parsing_command(line, data);
		data->inputfd = pipe(data->mypipefd);
		data->status = exec_command(data);
		ft_lstclear(&data->garbage_collector, &free);
		if (ft_strcmp(line, "exit\n") == 0)
			break ;
	}
}


		// int j;
		// t_list *lst;
		// lst = data->lst_parsing;
		// while (lst)
		// {
		// 	j = 0;
		// 	while (((t_parsing*)(lst->content))->arg[j])
		// 	{
		// 		ft_printf("parsing : arg[%d] : %s\n", j, ((t_parsing*)(lst->content))->arg[j]);
		// 		j++;
		// 	}
		// 	ft_printf("pipe : %d\n", ((t_parsing*)(lst->content))->pipe);
		// 	ft_printf("semicolon : %d\n", ((t_parsing*)(lst->content))->semicolon);
		// 	ft_printf("r_chevron : %d\n", ((t_parsing*)(lst->content))->r_chevron);
		// 	ft_printf("l_chevron : %d\n", ((t_parsing*)(lst->content))->l_chevron);
		// 	ft_printf("ld_chevron : %d\n\n\n", ((t_parsing*)(lst->content))->ld_chevron);
		// 	lst = lst->next;
		// }
			
			
		// ft_printf("parsing : arg[0] : %s\n", ((t_parsing*)(data->lst_parsing->content))->arg[0]);