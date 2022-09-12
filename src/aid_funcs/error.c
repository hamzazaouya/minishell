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
