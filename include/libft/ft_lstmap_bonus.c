/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:00:25 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/23 13:29:18 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*node;

	if (!f)
		return (NULL);
	n_lst = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&n_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&n_lst, node);
		lst = lst->next;
	}
	return (n_lst);
}
