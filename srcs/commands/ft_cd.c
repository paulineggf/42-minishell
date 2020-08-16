/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:37:57 by mcraipea          #+#    #+#             */
/*   Updated: 2020/03/02 12:40:17 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_home(char *path, t_data *data)
{
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	while (data->env[i])
	{
		if ((ft_strncmp(data->env[i], "HOME=", 5)) == 0)
		{
			j = 5;
			while (data->env[i][j])
				path[k++] = data->env[i][j++];
		}
		i++;
	}
}

static void		ft_cd_classic(char *path, t_parsing *parsing)
{
	int		i;
	int		k;

	k = 0;
	getcwd(path, 4096);
	i = ft_strlen(path);
	path[i++] = '/';
	while (parsing->arg[1][k])
		path[i++] = parsing->arg[1][k++];
}

static void		ft_cd_error(t_parsing *parsing, t_data *data)
{
	data->ret = 1;
	ft_putstr_fd("popo & max: cd: ", 2);
	ft_putstr_fd(parsing->arg[1], 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

static void		ft_cd_absolu(char *path, t_parsing *parsing)
{
	int		i;

	i = 0;
	while (parsing->arg[1][i])
	{
		path[i] = parsing->arg[1][i];
		i++;
	}
}

void			ft_cd(t_parsing *parsing, t_data *data)
{
	DIR				*p_dir;
	char			*path;

	easy_malloc((void**)&path, sizeof(char) * 4096, data);
	p_dir = opendir(parsing->arg[1]);
	if (parsing->arg[1] == NULL || (ft_strncmp(parsing->arg[1], "~", 2) == 0))
		ft_home(path, data);
	else if ((ft_strncmp(parsing->arg[1], "/", 2) == 0))
		path[0] = '/';
	else if ((ft_strncmp(parsing->arg[1], "/", 1) == 0))
		ft_cd_absolu(path, parsing);
	else if (!(p_dir))
	{
		ft_cd_error(parsing, data);
		return ;
	}
	else
		ft_cd_classic(path, parsing);
	ft_change_path(path, p_dir, data);
}
