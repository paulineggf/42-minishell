/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:31:03 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/06 12:59:15 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		printf_loop(t_list *lst, va_list *ap,
				int (*f[9])(va_list *, t_opt *))
{
	int		len;

	len = 0;
	while (lst)
	{
		if (!(((t_opt*)(lst->content))->str))
			len =
			(*f[((t_opt*)(lst->content))->type])(ap, (t_opt*)(lst->content))
			+ len;
		else
			len = ft_strlen(((t_opt*)(lst->content))->str) + len;
		write(1, ((t_opt*)(lst->content))->str, ((t_opt*)(lst->content))->len);
		free(((t_opt*)(lst->content))->str);
		((t_opt*)(lst->content))->str = NULL;
		lst = lst->next;
	}
	return (len);
}

int				ft_printf(const char *str, ...)
{
	t_list	*lst;
	t_list	*begin_list;
	int		len;
	va_list	ap;
	int		(*f[9])(va_list *, t_opt *);

	lst = NULL;
	if (!*str || !(lst = init_lst(ft_strdup(str))))
	{
		if (lst)
			ft_lstclear(&lst, &free);
		return (0);
	}
	begin_list = lst;
	init_ptrf(f);
	va_start(ap, str);
	len = printf_loop(lst, &ap, f);
	ft_lstclear(&begin_list, &free);
	free(begin_list);
	begin_list = NULL;
	va_end(ap);
	return (len);
}
