/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:31:14 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/21 12:37:56 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int				i;
	unsigned char	c;

	c = (unsigned char) ch;
	i = 0;
	if (c == 0)
		return ((char *)(str + ft_strlen(str)));
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}
