/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:19:13 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/19 13:19:48 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_change_path(char *path, DIR *p_dir, t_data *data)
{
	int		i;
	char	*repertoire;

	i = 0;
	easy_malloc((void**)&repertoire, sizeof(char) * 4096, data);
	while (data->env[i])
		i++;
	chdir(path);
	getcwd(repertoire, 4096);
	data->env = del_env2(&i, "PWD=", data);
	if (!(path = ft_strjoin("PWD=", repertoire)))
		exit_failure("ft_strjoin", data);
	add_garbage((void**)&path, data);
	data->env = add_env(&i, path, data);
	if (p_dir != NULL)
		closedir(p_dir);
	data->ret = 0;
}
