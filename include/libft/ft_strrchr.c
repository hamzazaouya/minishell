/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:30:34 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/21 12:34:29 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	memo;
	int	i;

	c = (unsigned char)c;
	i = 0;
	memo = -1;
	if (c == 0)
		return ((char *)(str + ft_strlen(str)));
	while (str[i])
	{
		if (str[i] == c)
			memo = i;
		i++;
	}
	if (memo != -1)
		return ((char *)(str + memo));
	return (0);
}
