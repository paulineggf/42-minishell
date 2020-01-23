/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:57:28 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/05 16:02:38 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*init_s(va_list *ap, t_opt *opt)
{
	char	*s;

	s_check_wildcard(ap, opt);
	s = va_arg(*ap, char *);
	if (s == NULL)
	{
		if (!(s = ft_strdup("(null)")))
			return (0);
	}
	else
	{
		if (!(s = ft_strdup(s)))
			return (0);
	}
	return (s);
}

static int		fill_opt(t_opt *opt, char *s)
{
	if (opt->point && opt->point != -2 &&
	(opt->tiret == -2 || opt->tiret == 0) && opt->nbr == 0)
	{
		if (!(opt->str = ft_strndup(s, opt->point)))
			return (s_free(s));
	}
	else if (opt->tiret && opt->point)
		return (s_tiret_point(opt, s));
	else if (opt->nbr && opt->point)
		return (s_nbr_point(opt, s));
	else if (opt->tiret)
		return (s_tiret(opt, s));
	else if (opt->nbr)
		return (s_nbr(opt, s));
	else
	{
		if (!(opt->str = ft_strdup(s)))
			return (s_free(s));
	}
	return (1);
}

int				fct_s(va_list *ap, t_opt *opt)
{
	char	*s;

	if (!(s = init_s(ap, opt)))
		return (0);
	if (*s == 0 || (opt->point == -2 && !opt->tiret && !opt->nbr))
		return (opt->len = ft_strlen(s_chaine_vide(opt)));
	if (!(fill_opt(opt, s)))
		return (0);
	free(s);
	return (opt->len = ft_strlen(opt->str));
}
