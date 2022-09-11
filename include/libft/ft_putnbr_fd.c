/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:34:00 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/22 14:36:07 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	char			c;

	nbr = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = -n;
	}
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	c = nbr % 10 + '0';
	write(fd, &c, 1);
}
