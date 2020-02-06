/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:59:15 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/06 17:49:32 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_execve(char *command, char **argument, char **env)
{
	int				i;
	char			*path;
	static char		**path_tab;
	int				j;
	int				k;
	char			*buf;

	path_tab = ft_calloc(sizeof(char*) * 12, 1);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = ft_strdup(env[i]);
		i++;
	}
	i = 5;
	j = 0;
	while (path[i])
	{
		k = 0;
		buf = ft_calloc(128, 1);
		while (path[i] != ':' && path[i])
		{
			buf[k++] = path[i];
			i++;
		}
		if (path[i] == ':')
			i++;
		path_tab[j] = ft_strdup(buf);
		j++;
	}
	i = 0;
	while (path_tab[i])
	{
		path_tab[i] = ft_strjoin(path_tab[i], "/");
		path_tab[i] = ft_strjoin(path_tab[i], command);
		if (execve(path_tab[i], argument, env) == -1)
			i++;
	}
	return (0);
}
