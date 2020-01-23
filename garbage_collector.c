/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:36:25 by mcraipea          #+#    #+#             */
/*   Updated: 2020/01/23 13:32:54 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			garbage_init(t_data *data)
{
	if (!(data->garbage_collector = malloc(sizeof(t_list))))
			return (0);
	return (1);
}

void	add_garbage(void **content, t_data *data)
{
	t_list	*new;

	if (!(new = ft_lstnew(*content)))
		exit_failure("Malloc failure\n", data);
	ft_lstadd_back(&(data->garbage_collector), new);
}

void	easy_malloc(void **content, size_t n, t_data *data)
{
	t_list	*new;

	if (!(*content = malloc(n)))
		exit_failure("Malloc failure\n", data);
	ft_bzero(*content, n);
	if (!(new = ft_lstnew(*content)))
		exit_failure("Malloc failure\n", data);
	ft_lstadd_back(&(data->garbage_collector), new);
}

void		exit_failure(char *str, t_data *data)
{
	ft_lstclear(&(data->garbage_collector), &free);
	free(data);
	if (str)
		ft_putstr_fd(str, 2);
	//exit(0);
}

