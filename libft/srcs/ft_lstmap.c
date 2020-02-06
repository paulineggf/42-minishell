/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:20:40 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/24 11:15:20 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list *new;
	t_list *begin_list;

	if (!lst || !f)
		return (NULL);
	begin_list = NULL;
	while (lst)
	{
		if (!begin_list)
		{
			if (!(new = ft_lstnew((*f)(lst->content))))
				return (NULL);
			begin_list = new;
		}
		else
			new->next = ft_lstnew((*f)(lst->content));
		lst = lst->next;
	}
	return (begin_list);
}
