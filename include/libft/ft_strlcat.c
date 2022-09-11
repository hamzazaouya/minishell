/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:05:18 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/21 11:18:40 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (dstsize == 0 && !dest)
		return (ft_strlen(src));
	i = 0;
	j = ft_strlen(dest);
	if (j < dstsize)
	{
		while (src[i] && j < (dstsize - 1))
		{
			dest[j] = src[i];
			i++;
			j++;
		}
		dest[j] = 0;
	}
	if ((j - i) >= dstsize)
		return (dstsize + ft_strlen(src));
	return (ft_strlen(src) + j - i);
}
