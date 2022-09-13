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

void	ft_update_pwd(t_env **env, char *old_pwd)
{
	char	*pwd;

	pwd = NULL;
	pwd = getcwd(pwd, BUFFER_SIZE);
	*env = ft_ch_value(*env, "PWD", pwd);
	*env = ft_ch_value(*env, "OLDPWD", old_pwd);
	if (pwd)
		free(pwd);
}

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
