/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:22:50 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/28 14:56:40 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			is_separator(char **str, int i, t_parsing *struct_parsing)
{
	if (!str[i])
		return (1);
	else if (!ft_strcmp(str[i], PIPE))
		struct_parsing->pipe = 1;
	else if (!ft_strcmp(str[i], SEMICOLON))
		struct_parsing->semicolon = 1;
	else if (!ft_strcmp(str[i], R_QUOTE))
		struct_parsing->r_quote = 1;
	else if (!ft_strcmp(str[i], L_QUOTE))
		struct_parsing->l_quote = 1;
	else if (!ft_strcmp(str[i], RD_QUOTES))
		struct_parsing->rd_quotes = 1;
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
	if (!(new = ft_calloc(*j + 2, sizeof(char*))))
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

static t_parsing	fill_arg(int *i, t_data *data)
{
	int			j;
	t_list		*new;
	t_parsing	struct_parsing;

	j = 1;
	ft_bzero(&struct_parsing, sizeof(t_parsing));
	if (!(struct_parsing.arg = ft_calloc(2, sizeof(char*))))
		exit_failure("ft_calloc", data);
	if (!(new = ft_lstnew(struct_parsing.arg)))
		exit_failure("ft_lstnew", data);
	ft_lstadd_front(&(data->garbage_collector), new);
	if (!(struct_parsing.arg[0] = ft_strdup(data->str_split[*i])))
		exit_failure("ft_strdup", data);
	add_garbage((void**)&(struct_parsing.arg[0]), data);
	free(data->str_split[*i]);
	(*i)++;
	while (!is_separator(data->str_split, *i, &struct_parsing))
	{
		struct_parsing.arg = add_arg(struct_parsing.arg, &j, *i, data);
		free(data->str_split[*i]);
		(*i)++;
		j++;
	}
	if (data->str_split[*i])
		(*i)++;
	return (struct_parsing);
}

t_list				*parsing_command(char *line, t_data *data)
{
	int			i;
	t_list		*lst;
	t_list		*new;
	t_parsing	struct_parsing;

	i = 0;
	lst = NULL;
	if (!(data->str_split = ft_split(line, ' ')))
		exit_failure("ft_split", data);
	add_garbage((void**)&data->str_split, data);
	while (data->str_split[i])
	{
		struct_parsing = fill_arg(&i, data);
		if (!(new = ft_lstnew((void*)&struct_parsing)))
			exit_failure("ft_lstnew", data);
		ft_lstadd_back(&lst, new);
		add_garbage((void**)&(new), data);
		// printf("%s\n%s\n%s\n%d\n", ((t_parsing*)(new->content))->arg[0],
		// ((t_parsing*)(new->content))->arg[1],
		// ((t_parsing*)(new->content))->arg[2],
		// ((t_parsing*)(new->content))->pipe);
	}
	return (lst);
}
