/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:59:15 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/17 16:38:44 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_path(char *path, t_data *data)
{
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	while (data->env[i])
	{
		if ((ft_strncmp(data->env[i], "PATH=", 5)) == 0)
		{
			j = 5;
			while (data->env[i][j])
				path[k++] = data->env[i][j++];
		}
		i++;
	}
}

static void		ft_path_tab(char *path, char **path_tab, t_data *data)
{
	char			buf[4096];
	int				j;
	int				k;
	int				i;

	i = 0;
	j = 0;
	while (path[i])
	{
		k = 0;
		ft_bzero(buf, 4096);
		while (path[i] != ':' && path[i])
			buf[k++] = path[i++];
		if (path[i] == ':')
			i++;
		if (!(path_tab[j] = ft_strdup(buf)))
			exit_failure("ft_strdup", data);
		add_garbage((void**)&path_tab[j], data);
		j++;
	}
}

static void		ft_execve2(char *path, char **path_tab,
				t_parsing *tmp, t_data *data)
{
	int			i;

	i = 0;
	ft_path(path, data);
	ft_path_tab(path, path_tab, data);
	while (path_tab[i])
	{
		if (!(path_tab[i] = ft_strjoin(path_tab[i], "/")))
			exit_failure("ft_strjoin", data);
		add_garbage((void**)&path_tab[i], data);
		if (!(path_tab[i] = ft_strjoin(path_tab[i], tmp->arg[0])))
			exit_failure("ft_strjoin", data);
		add_garbage((void**)&path_tab[i], data);
		if (execve(path_tab[i], tmp->arg, data->env) == -1)
			i++;
	}
	exit_failure(NULL, data);
}

int				ft_execve(t_parsing *tmp, t_data *data)
{
	char			path[4096];
	static char		**path_tab;

	if (!(path_tab = ft_calloc(sizeof(char*) * 128, 1)))
		exit_failure("ft_calloc", data);
	add_garbage((void**)&path_tab, data);
	ft_bzero(path, 4096);
	if ((ft_strncmp(tmp->arg[0], "/", 1)) == 0)
	{
		if (execve(tmp->arg[0], tmp->arg, data->env) == -1)
			return (0);
		exit_failure(NULL, data);
	}
	else
		ft_execve2(path, path_tab, tmp, data);
	return (0);
}
