/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:22:50 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/03 10:34:03 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			is_separator(char **str, int i, t_parsing *struct_parsing)
{
	if (str[i] == NULL)
		return (1);
	else if (!ft_strcmp(str[i], PIPE))
		struct_parsing->pipe += 1;
	else if (!ft_strcmp(str[i], R_CHEVRON))
		struct_parsing->r_chevron += 1;
	else if (!ft_strcmp(str[i], L_CHEVRON))
		struct_parsing->l_chevron += 1;
	else if (!ft_strcmp(str[i], LD_CHEVRON))
		struct_parsing->ld_chevron += 1;
	else if (!ft_strcmp(str[i], SEMICOLON))
		return (2);
	else
		return (0);
	return (1);
}

static char			**add_arg(char **arg, int *j,
				int i, t_data *data)
{
	int			k;
	char		**new;
	t_list		*new_list;

	k = 0;
	if (!(new = ft_calloc(*j + 1, sizeof(char*))))
		exit_failure("malloc", data);
	if (!(new_list = ft_lstnew(new)))
		exit_failure("ft_lstnew", data);
	ft_lstadd_front(&(data->garbage_collector), new_list);
	while (arg[k] != NULL)
	{
		if (!(new[k] = ft_strdup(arg[k])))
			exit_failure("ft_strdup", data);
		add_garbage((void**)&new[k], data);
		k++;
	}
	if (!(new[k] = ft_strdup(data->str_split[i])))
		exit_failure("ft_strdup", data);
	add_garbage((void**)&new[k], data);
	return (new);
}

static t_parsing	*fill_arg(int *i, t_data *data)
{
	int			j;
	t_list		*new;
	t_parsing	*struct_parsing;

	j = 1;
	easy_malloc((void**)&struct_parsing, sizeof(t_parsing), data);
	if (!(struct_parsing->arg = ft_calloc(1, sizeof(char*))))
		exit_failure("ft_calloc", data);
	if (!(new = ft_lstnew(struct_parsing->arg)))
		exit_failure("ft_lstnew", data);
	ft_lstadd_front(&(data->garbage_collector), new);
	if (!(struct_parsing->files = ft_calloc(1, sizeof(char*))))
		exit_failure("ft_calloc", data);
	if (!(new = ft_lstnew(struct_parsing->files)))
		exit_failure("ft_lstnew", data);
	ft_lstadd_front(&(data->garbage_collector), new);	
	while (!is_separator(data->str_split, *i, struct_parsing))
	{
		struct_parsing->arg = add_arg(struct_parsing->arg, &j, *i, data);
		(*i)++;
		j++;
	}
	j = 1;
	if (is_separator(data->str_split, *i, struct_parsing) == 1)
	while (ft_strcmp(data->str_split[*i], L_CHEVRON) == 0)
	{
		(*i)++;
		struct_parsing->files = add_arg(struct_parsing->files, &j, *i, data);
		(*i)++;
		is_separator(data->str_split, *i, struct_parsing);
		j++;
	}
	if (data->str_split[*i])
		(*i)++;
	return (struct_parsing);
}

t_list				*parsing_command(char *line, t_data *data)
{
	int			i;
	t_list		*new;
	t_list		*begin_list;
	t_parsing	*struct_parsing;

	i = 0;
	begin_list = NULL;
	if (!(data->str_split = split_shell(line)))
		exit_failure("split_shell", data);
	add_garbage((void**)&data->str_split, data);
	while (data->str_split[i])
	{
	 	struct_parsing = fill_arg(&i, data);
		if (!(new = ft_lstnew((void*)struct_parsing)))
			exit_failure("ft_lstnew", data);
		ft_lstadd_back(&begin_list, new);
		add_garbage((void**)&(new), data);
	}
	return (begin_list);
}






	// int j;
	// t_list *lst;
	// lst = begin_list;
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
	// 	ft_printf("ld_chevron : %d\n", ((t_parsing*)(lst->content))->ld_chevron);
	// 	lst = lst->next;
	// }