/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:46:22 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/21 10:48:55 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*memo;
	unsigned char	ch;

	i = 0;
	memo = (unsigned char *)b;
	ch = (unsigned char )c;
	while (i < len)
	{
		memo[i] = c;
		i++;
	}
	return (b);
}
