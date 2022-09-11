/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:28:09 by labenall          #+#    #+#             */
/*   Updated: 2022/09/11 16:28:13 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_echo_n(char *src)
{
	int	i;

	if (!src)
		return (0);
	i = 0;
	if (src[i] == '-')
	{
		i++;
		if (src[i] != 'n')
			return (0);
		while (src[i] == 'n')
			i++;
	}
	if (src[i] == 0)
		return (1);
	return (0);
}

void	my_echo(char **src)
{
	int	i;
	int	n;
	int	count;

	n = 0;
	i = 1;
	while (ft_echo_n(src[i]))
	{
		n = 1;
		i++;
	}
	count = i;
	while (src[count])
		count++;
	while (src[i])
	{
		printf("%s", src[i]);
		i++;
		if (i != count)
			printf(" ");
	}
	if (n == 0)
		printf("\n");
}
