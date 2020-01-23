/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:21:07 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/07 14:45:19 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_op
{
	char		*str;
	int			len;
	int			type;
	int			tiret;
	int			nbr;
	int			zero;
	int			point;
	int			wildcard_zero;
	int			wildcard_tiret;
	int			wildcard_point;
	int			wildcard_nbr;
}				t_opt;

int				ft_printf(const char *str, ...);
int				ft_atoi_printf(char *s, int *i, char c);
int				fct_p(va_list *ap, t_opt *opt);
void			p_check_wildcard(va_list *ap, t_opt *opt);
char			*p_tiret(char *s, int nb);
char			*p_nbr(char *s, int nb);
char			*p_0x(char *s);
int				fct_c(va_list *ap, t_opt *opt);
void			c_check_wildcard(va_list *ap, t_opt *opt);
int				c_tiret(t_opt *opt, char *s);
int				c_nbr(t_opt *opt, char *s);
char			*c_chaine_vide(t_opt *opt);
int				fct_s(va_list *ap, t_opt *opt);
void			s_check_wildcard(va_list *ap, t_opt *opt);
int				s_tiret(t_opt *opt, char *s);
int				s_tiret_point(t_opt *opt, char *s);
int				s_nbr_point(t_opt *opt, char *s);
int				s_nbr(t_opt *opt, char *s);
int				s_free(char *s);
char			*s_chaine_vide(t_opt *opt);
int				fct_id(va_list *ap, t_opt *opt);
int				id_zero_point(t_opt *opt, char *s);
int				id_nbr(t_opt *opt, char *s);
int				id_point(t_opt *opt, char *s);
int				id_tiret(t_opt *opt, char *s);
int				id_zero(t_opt *opt, char *s);
int				id_tiret_point(t_opt *opt, char *s);
int				id_nbr_point(t_opt *opt, char *s);
void			id_check_wildcard(va_list *ap, t_opt *opt);
char			*id_chaine_vide(t_opt *opt);
int				fct_u(va_list *ap, t_opt *opt);
int				u_zero_point(t_opt *opt, char *s);
int				u_nbr(t_opt *opt, char *s);
int				u_point(t_opt *opt, char *s);
int				u_tiret(t_opt *opt, char *s);
int				u_zero(t_opt *opt, char *s);
int				u_tiret_point(t_opt *opt, char *s);
int				u_nbr_point(t_opt *opt, char *s);
void			u_check_wildcard(va_list *ap, t_opt *opt);
char			*u_chaine_vide(t_opt *opt);
char			*u_chaine_vide(t_opt *opt);
int				fct_x(va_list *ap, t_opt *opt);
int				x_point(t_opt *opt, char *s);
int				x_tiret(t_opt *opt, char *s);
int				x_nbr_point(t_opt *opt, char *s);
int				x_tiret_point(t_opt *opt, char *s);
int				x_zero_point(t_opt *opt, char *s);
void			x_check_wildcard(va_list *ap, t_opt *opt);
int				x_zero(t_opt *opt, char *s);
int				x_nbr(t_opt *opt, char *s);
char			*x_chaine_vide(t_opt *opt);
int				fct_pourcentage(va_list *ap, t_opt *opt);
int				pourc_nbr(t_opt *opt, char *s);
int				pourc_tiret(t_opt *opt, char *s);
void			pourc_check_wildcard(va_list *ap, t_opt *opt);
int				pourc_zero(t_opt *opt, char *s);
void			c_check_wildcard(va_list *ap, t_opt *opt);
int				match_type(char c);
void			init_ptrf(int (**f)(va_list *ap, t_opt *opt));
t_list			*init_lst(char *str);
char			*convert_hex(unsigned long nb,
char *base, unsigned long len_base);

#endif
