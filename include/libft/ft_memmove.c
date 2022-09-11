/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:50:40 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/21 11:08:59 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dt;
	unsigned char	*sr;

	dt = (unsigned char *)dst;
	sr = (unsigned char *)src;
	if (sr < dt)
		while (len--)
			dt[len] = sr[len];
	else
		return (ft_memcpy(dst, src, len));
	return (dt);
}
