/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:49:09 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/10 11:01:40 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_cd(t_data * data)
{
	DIR		*p_dir;
	char	*line;
	char	*rep;
	char	*path;

	if (!(p_dir = opendir(line)))
	{
		ft_printf("Cannot open directory <%s>\n", line);
		// return (0);  Ne pas return 0 mais exit_failure peut etre 
	}
	getcwd(rep, 4096);
	path = ft_strdup(rep);
	path = ft_strjoin(path, "/");
	path = ft_strjoin(path, line);
	chdir(path);
	closedir(p_dir);
	dup2(data->savestdout, STDOUT_FILENO);
	dup2(data->savestdin, STDIN_FILENO);
	return (1);
}
