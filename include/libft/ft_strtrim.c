/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:28:25 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/22 13:43:57 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		end;
	int		start;
	char	*str;

	start = 0;
	i = 0;
	str = NULL;
	if (!s1 || !ft_strlen(s1))
		return (ft_calloc(1, sizeof(char)));
	end = ft_strlen(s1) - 1;
	while (is_set(s1[start], set))
		start++;
	while (end > start && is_set(s1[end], set))
		end--;
	str = (char *) malloc(sizeof(char) * (end - start) + 2);
	if (!str)
		return (NULL);
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
