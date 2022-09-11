/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:13:35 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/21 12:47:57 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char	*ft_strdup(const char *src)
{
	int		size;
	char	*cpy;

	size = ft_strlen(src);
	cpy = (char *)malloc(sizeof(char) * (size + 1));
	if (!cpy)
		return (NULL);
	ft_strcpy(cpy, src);
	return (cpy);
}
