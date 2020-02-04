/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:55:57 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/04 18:15:14 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**		Protection car si pwd plus grand que 4096, renvoie NULL
**		Voir si on peut faire une fonction pour allouer plus grand si besoin
*/

char	*ft_prompt(t_data *data)
{
	char			*str_prompt;
	char			pwd[4096];

	if (!(str_prompt = ft_strdup("popo & max@ ")))
		exit_failure("ft_strdup", data);
	add_garbage((void**)&str_prompt, data);
	if (!(getcwd(pwd, 4096)))
		return (NULL);
	if (!(str_prompt = ft_strjoin(str_prompt, pwd)))
		exit_failure("ft_strjoin", data);
	add_garbage((void**)&str_prompt, data);
	if (!(str_prompt = ft_strjoin(str_prompt, " : ")))
		exit_failure("ft_strjoin", data);
	add_garbage((void**)&str_prompt, data);
	return (str_prompt);
}
