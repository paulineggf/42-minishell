/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:41:52 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/11 16:27:10 by mcraipea         ###   ########.fr       */
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
# include <signal.h>
# include <sys/wait.h>
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
	char			**env;
	int				inputfd;
	int				ret;
	int				status;
	int				savestdout;
	int				savestdin;
	pid_t			pid;
	int				mypipefd[2];
	char			*str_prompt;
	char			**str_split;
	t_list			*lst_parsing;
	t_list			*garbage_collector;
}					t_data;

/* COMMANDS */

// commands
int					ft_echo(t_parsing *parsing, t_data *data);
void				ft_export(t_parsing *tmp, t_data *data);
void				ft_unset(t_parsing *tmp, t_data *data);
int					ft_env(t_data *data);
int					ft_pwd(t_data *datas);
int					ft_cd(t_parsing *parsing, t_data *data);

/* EXEC_COMMAND */

int					exec_command(t_data *data);
int 			    exec_command_env(t_parsing *tmp, t_data *data);
int					ft_execve(t_parsing *tmp, t_data *data);
int					is_builtin(t_parsing *parsing, t_data *data);
void				left_chevron(t_list **tmp, t_data *data);
void				right_chevron(t_list **tmp, t_data *data);
void				double_left_chevron(t_list **tmp, t_data *data);


/* INIT_PROGRAM */

// parsing
t_list				*parsing_command(char *line, t_data *data);
int					len_tabtab(char **str);
char				**add_arg2(char **tmp1, char **tmp2, t_data *data);
char				**ft_init_env(char **env, t_data *data);

// split_shell
char				**split_shell(char *str, t_data *data);
void			    ft_new_line(char *buf, char **tab, t_data *data);
void				ft_simple_quote(int *i, char *str, char **tab, t_data *data);
void				ft_double_quote(int *i, char *str, char **tab, t_data *data);
void			    ft_line_basic(int *i, char *str, char **tab, t_data *data);
void				ft_chevron(int *i, char *str, char **tab, t_data *data);
void				ft_error(int flag_double, int flag_simple, t_data *data);
void				control_env(char **tab, t_data *data);
char				*ft_del_slash(char *str, int j, t_data *data);
void				ft_other_case(int *i, char *str, char **tab, t_data *data);
void				ft_else_split(int *i, char *str, char **tab, t_data *data);

// garbage collector
void				garbage_init(t_data *data);
void				add_garbage(void **content, t_data *data);
void				easy_malloc(void **content, size_t n, t_data *data);
void				exit_failure(char *str, t_data *data);
void				exit_failure2(t_data *data);

// prompt
char 				*ft_prompt(t_data *data);

// main
int					main(int argc, char **argv, char **env);
void				main_function(t_data *data);
void				minishell_signals(void);
void				minishell_signals2(void);

#endif