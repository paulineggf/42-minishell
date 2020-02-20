/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:41:52 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/20 15:36:45 by pganglof         ###   ########.fr       */
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
# include <errno.h>
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
	int				verif_path;
	int				status;
	int				savestdout;
	int				savestdin;
	pid_t			pid;
	int				fd0[2];
	int				fd1[2];
	int				fd2[2];
	int				pipe2;
	char			*str_prompt;
	char			**str_split;
	t_list			*lst_parsing;
	t_list			*garbage_collector;
}					t_data;

int					ft_echo(t_parsing *parsing, t_data *data);
void				ft_export(t_parsing *tmp, t_data *data);
char				**add_env(int *i, char *value, t_data *data);
char				**del_env2(int *i, char *value, t_data *data);
char				**del_env3(char *value, int size, int *i, t_data *data);
void				ft_unset(t_parsing *tmp, t_data *data);
int					ft_env(t_data *data);
int					ft_pwd(t_data *datas);
void				ft_cd(t_parsing *parsing, t_data *data);
void				ft_change_path(char *path, DIR *p_dir, t_data *data);
int					ft_exit(t_parsing *tmp, t_data *data);
void				exec_command(t_list **lst, t_data *data);
int					exec_command_env(t_parsing *tmp, t_data *data);
int					ft_execve(t_parsing *tmp, t_data *data);
int					is_builtin(t_parsing *parsing, t_data *data);
void				pipe_command(t_parsing *tmp, t_list **lst, t_data *data);
void				pipe_command_bis(t_parsing *tmp, t_list **lst,
					t_data *data);
void				left_chevron(t_list **tmp, t_data *data);
void				right_chevron(t_list **tmp, t_data *data);
int					check_separator(t_list **lst, t_data *data);
void				double_left_chevron(t_list **tmp, t_data *data);
t_list				*parsing_command(char *line, t_data *data);
int					len_tabtab(char **str);
char				**add_arg2(char **tmp1, char **tmp2, t_data *data);
char				**ft_init_env(char **env, t_data *data);
char				**split_shell(char *str, t_data *data);
void				ft_new_line(char *buf, char **tab, t_data *data);
void				ft_simple_quote(int *i, char *str,
					char **tab, t_data *data);
void				ft_double_quote(int *i, char *str,
					char **tab, t_data *data);
int					ft_simple_quote2(int *i, int *j, char *str, char *buf);
int					ft_double_quote2(int *i, int *j, char *str, char *buf);
void				ft_line_basic(int *i, char *str, char **tab, t_data *data);
void				ft_chevron(int *i, char *str, char **tab, t_data *data);
void				ft_error(int flag_double, int flag_simple, t_data *data);
char				*control_env(char *tab, t_data *data);
void				ft_del_slash(int *i, int *j, char *str, char *buf);
void				ft_other_case(int *i, char *str, char **tab, t_data *data);
void				ft_else_split(int *i, char *str, char **tab, t_data *data);
char				*ft_correctif(char c, char *str, t_data *data);
void				garbage_init(t_data *data);
void				add_garbage(void **content, t_data *data);
void				easy_malloc(void **content, size_t n, t_data *data);
void				exit_failure(char *str, t_data *data);
void				exit_failure2(int ret, char *s1, char *s2, t_data *data);
char				*ft_prompt(t_data *data);
int					main(int argc, char **argv, char **env);
void				main_function(t_data *data);
void				minishell_signals(void);
void				minishell_signals2(void);

#endif
