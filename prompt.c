/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:55:57 by mcraipea          #+#    #+#             */
/*   Updated: 2020/01/23 13:32:23 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *prompt(t_data *data)
{
	char			*prompt;
	char			*pwd;

	if (!(prompt = ft_strdup("popo & max@ ")))
		exit_faillure("error", data);//stderror("strdup")
	add_garbage(&prompt, data);
	if (!(getcwd(pwd, 4096)))
		return (NULL);
		//protection car si pwd plus grand que 4096, renvoie NULL
		//voir si on peut faire une fonction pour allouer plus grand si besoin
	if (!(prompt = ft_strjoin(prompt, pwd)))
		exit_faillure("error", data);//stderror("strdup")
	add_garbage(&prompt, data);
	if (!(prompt = ft_strjoin(prompt, " : ")))
		exit_faillure("error", data);//stderror("strdup")
	add_garbage(&prompt, data);
	return (prompt);
}