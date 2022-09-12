/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:35:50 by labenall          #+#    #+#             */
/*   Updated: 2022/09/11 18:35:52 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../include/minishell.h"

void	*single_double_qoute_err(char *value)
{
	free(value);
	write(2, "Error: No Closing qoute\n", ft_strlen("Error: No Closing qoute\n"));
	data->exit_code = 1;
	return (NULL);
}

char	*ft_itoa(int n)
{
	unsigned int	n_holder;
	int				negatif;
	int				nbr_len;
	char			*result;

	negatif = 1;
	nbr_len = 0;
	if (n < 0)
	{
		negatif = -1;
		nbr_len = 1;
	}
	n_holder = n * negatif;
	if ((n_holder > 2147483648) || \
		(n_holder > 2147483647 && negatif == 1))
		return (NULL);
	nbr_len += ft_count_len(n_holder);
	result = (char *)malloc((nbr_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_itoa_writer(result, nbr_len, n_holder);
	if (negatif < 0)
		result[0] = '-';
	result[nbr_len] = '\0';
	return (result);
}

void	ft_free_char_array(char **char_array)
{
	int	index;

	index = 0;
	while (char_array[index])
	{
		free(char_array[index]);
		index++;
	}
	if (char_array)
		free(char_array);
	return ;
}
