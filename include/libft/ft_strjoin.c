/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:08:35 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/21 13:49:52 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	len = i + ft_strlen(s2) + 1;
	str = (char *) malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len);
	ft_strlcpy(str + i, s2, len);
	return (str);
}
