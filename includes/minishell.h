/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:41:52 by mcraipea          #+#    #+#             */
/*   Updated: 2020/01/29 19:09:51 by pganglof         ###   ########.fr       */
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
# include <string.h>
# include "libft.h"
# include "ft_printf.h"

# define PIPE 		"|"
# define SEMICOLON 	";"
# define R_CHEVRON	"<"
# define L_CHEVRON	">"
# define LD_CHEVRON	">>"

typedef struct		s_parsing
{
	char			**arg;
	int				pipe;
	int				semicolon;
	int				r_chevron;
	int				l_chevron;
	int				ld_chevron;
}					t_parsing;

typedef struct		s_data
{
	char			**str_split;
	t_list			*lst_parsing;
	t_list			*garbage_collector;
}					t_data;

//parsing
t_list				*parsing_command(char *line, t_data *data);
char				**split_shell(char *str);

//garbage collector
void				garbage_init(t_data *data);
void				add_garbage(void **content, t_data *data);
void				easy_malloc(void **content, size_t n, t_data *data);
void				exit_failure(char *str, t_data *data);

//prompt
char 				*ft_prompt(t_data *data);

//main
int					main(int argc, char **argv, char **env);

#endif