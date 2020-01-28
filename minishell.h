/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:41:52 by mcraipea          #+#    #+#             */
/*   Updated: 2020/01/28 16:28:32 by mcraipea         ###   ########.fr       */
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
# include "./libft/includes/libft.h"
# include "./libft/includes/ft_printf.h"


typedef struct			s_data
{
	struct s_list		*garbage_collector;
}						t_data;


//garbage collector
int			garbage_init(t_data *data);
void		add_garbage(void **content, t_data *data);
void		easy_malloc(void **content, size_t n, t_data *data);
void		exit_failure(char *str, t_data *data);

//prompt
char 		*prompt(t_data *data);

//main
int			main(int argc, char **argv);

//builtin
void		do_echo(char *line);
int			do_cd(char *line);
void		do_env(char *line, char **env);
void		do_export(char *line, char **env);
void		do_pwd();


char		**split_shell(char *str);


#endif