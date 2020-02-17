/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:22:50 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/17 14:25:40 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			is_separator(char **str, int i, t_parsing *struct_parsing)
{
	if (!str[i])
	{
		struct_parsing->semicolon = 1;
		return (1);
	}
	else if (!ft_strcmp(str[i], PIPE))
		struct_parsing->pipe = 1;
	else if (!ft_strcmp(str[i], SEMICOLON))
		struct_parsing->semicolon = 1;
	else if (!ft_strcmp(str[i], R_CHEVRON))
		struct_parsing->r_chevron = 1;
	else if (!ft_strcmp(str[i], L_CHEVRON))
		struct_parsing->l_chevron = 1;
	else if (!ft_strcmp(str[i], LD_CHEVRON))
		struct_parsing->ld_chevron = 1;
	else
		return (0);
	return (1);
}

static char			**add_arg(char **arg, int *j,
					int i, t_data *data)
{
	int			k;
	char		**new;

	k = 0;
	easy_malloc((void**)&new, sizeof(char*) * (*j + 1), data);
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
	t_parsing	*struct_parsing;

	j = 1;
	easy_malloc((void**)&struct_parsing, sizeof(t_parsing), data);
	easy_malloc((void**)&struct_parsing->arg, sizeof(char*), data);
	while (!is_separator(data->str_split, *i, struct_parsing))
	{
		struct_parsing->arg = add_arg(struct_parsing->arg, &j, *i, data);
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
	t_list		*new;
	t_list		*begin_list;
	t_parsing	*struct_parsing;

	i = 0;
	begin_list = NULL;
	data->str_split = split_shell(line, data);
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
