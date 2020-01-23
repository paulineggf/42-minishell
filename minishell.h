/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:41:52 by mcraipea          #+#    #+#             */
/*   Updated: 2020/01/23 13:18:10 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <dirent.h>
/* pour l'utilisation des dossiers */
# include "libft.h"
# include "ft_printf.h"


typedef struct			s_data
{
	struct t_list		*garbage_collector;
}						t_data;


//garbage collector
int			garbage_init(t_data *data);
void		add_garbage(t_data *data);
void		easy_malloc(void **content, size_t n, t_data *data);
void		exit_failure(char *str, t_data *data);

//prompt
char 		*prompt(void);

//main
int			main(int argc, char **argv, char **env);

#endif