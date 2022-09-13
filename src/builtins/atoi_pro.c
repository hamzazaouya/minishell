/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:28:33 by labenall          #+#    #+#             */
/*   Updated: 2022/09/11 17:00:15 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/builtins.h"
#include "limits.h"

static	int	cas(int s, int *r)
{
	*r = 1;
	if (s == 1)
		return (-1);
	else
		return (0);
}

static int	invalid_number(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int	sign(char **str, int *s)
{
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	if (**str == '-')
	{
		*s = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	if (invalid_number(*str) == -1)
		return (-1);
	return (0);
}

int	ft_atoi_pro(char *str, int *r)
{
	int						s;
	unsigned long long		res;
	unsigned long long		stock;

	s = 1;
	res = 0;
	*r = 0;
	if (sign(&str, &s) == -1)
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		stock = res;
		res = res * 10 + *str - '0';
		if (s == 1 && (stock > res || res > LONG_MAX))
			return (cas(s, r));
		else if (s == -1 && (stock > res || (s * res < (LONG_MIN))))
			return (cas(s, r));
		str++;
	}
	return (s * res);
}
