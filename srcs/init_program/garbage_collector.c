/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:36:25 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/12 10:24:04 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		garbage_init(t_data *data)
{
	if (!(data->garbage_collector = malloc(sizeof(t_list))))
		exit_failure("malloc", data);
	ft_bzero(data->garbage_collector, sizeof(t_list));
}

void		add_garbage(void **content, t_data *data)
{
	t_list	*new;

	if (!(new = ft_lstnew(*content)))
		exit_failure("ft_lstnew", data);
	ft_lstadd_back(&(data->garbage_collector), new);
}

void		easy_malloc(void **content, size_t n, t_data *data)
{
	t_list	*new;

	if (!(*content = ft_calloc(1, n)))
		exit_failure("ft_calloc", data);
	if (!(new = ft_lstnew(*content)))
		exit_failure("ft_lstnew", data);
	ft_lstadd_back(&(data->garbage_collector), new);
}

void		exit_failure(char *str, t_data *data)
{
	ft_lstclear(&(data->garbage_collector), &free);
	if (str)
		ft_putstr_fd(str, 2);
	data->status = 1;
	main_function(data);
}

void		exit_failure2(t_data *data)
{
	int			i;

	i = 0;
	ft_lstclear(&(data->garbage_collector), &free);
	while (data->env[i])
	{
		free(data->env[i]);
		i++;
	}
	free(data);
	ft_putstr_fd("exit\n", 2);
	exit(0);
}
