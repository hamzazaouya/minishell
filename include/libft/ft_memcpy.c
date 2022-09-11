/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:39:31 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/21 12:43:59 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	unsigned char	*dt;
	unsigned char	*sr;
	size_t			i;

	dt = (unsigned char *) dest;
	sr = (unsigned char *) src;
	if (dest == 0 && src == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		dt[i] = sr[i];
		i++;
	}
	return ((void *)(dt));
}
