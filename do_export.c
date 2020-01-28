/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 14:56:34 by mcraipea          #+#    #+#             */
/*   Updated: 2020/01/23 16:22:42 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//pas bon!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void		do_export(char *line, char **env)
{
	int			i;
	int			j;
	char		*name_env = NULL;
	char		*valeur_env = NULL;

	i = 0;
	j = 0;
	while (line[i] != '=')
		name_env[j++] = line[i++];
	i++;
	j = 0;
	while (ft_isprint(line[i] != 0))
		valeur_env[j] = line[i];
	while (env[i])
	{
		if (strcmp(env[i], line) == 0)
			i++;
	}
}
