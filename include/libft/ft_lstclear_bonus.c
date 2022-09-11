/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:36:48 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/23 13:17:26 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		head = *lst;
		del(head->content);
		*lst = (*lst)->next;
		free(head);
	}
}
