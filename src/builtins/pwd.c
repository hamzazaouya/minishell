/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:28:54 by labenall          #+#    #+#             */
/*   Updated: 2022/09/11 16:28:56 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_pwd(void)
{
	char	*str;

	str = NULL;
	str = getcwd(str, BUFFER_SIZE);
	if (str == NULL)
	{
		write(1, "cd: An error occured while getting cwd\n", 39);
		return (EXIT_FAILURE);
	}
	else
		printf("%s\n", str);
	free(str);
	return (EXIT_SUCCESS);
}
