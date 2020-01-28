/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:53:46 by mcraipea          #+#    #+#             */
/*   Updated: 2020/01/23 16:30:48 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		do_cd(char *line)
{
	DIR				*p_dir;
	char			*rep;
	char			*path;

	p_dir = opendir(line);//line=argument que l'on aura dans data
	if (p_dir == NULL)
	{
		ft_putstr("Cannot open directory <");
		ft_putstr(line);
		ft_putstr(">\n");
		return (0);
	}
	getcwd(rep, 4096);
	path = ft_strdup(rep);
	path = ft_strjoin(path, "/");
	path = ft_strjoin(path, line);
	chdir(path);
	closedir (p_dir);
	return (1);
}
