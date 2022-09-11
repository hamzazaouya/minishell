/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:44:11 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/21 13:51:34 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_calc(int n)
{
	unsigned int	num;
	int				ctr;

	num = n;
	ctr = 0;
	if (n < 0)
	{
		num = -n;
		ctr++;
	}
	else if (n == 0)
		return (1);
	while (num > 0)
	{
		ctr++;
		num /= 10;
	}
	return (ctr);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*str;
	unsigned int	num;

	num = n;
	i = ft_num_calc(n);
	str = (char *) ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else if (n == 0)
		str[0] = '0';
	str[i--] = 0;
	while (num > 0)
	{
		str[i--] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
