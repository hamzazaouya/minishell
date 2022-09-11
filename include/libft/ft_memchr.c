/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:50:44 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/21 12:39:10 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	value;
	unsigned char	*st;

	st = (unsigned char *)str;
	value = (unsigned char )c;
	i = 0;
	while (i < n)
	{
		if (st[i] == value)
			return (st + i);
		i++;
	}
	return (0);
}
