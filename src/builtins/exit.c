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

int	is_not_number(char *s)
{
	int	i;
	int	n;
	int	r;

	i = 0;
	if (s == NULL)
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	n = ft_atoi_pro(s, &r);
	if (r)
		return (1);
	else
		return (0);
}

int	cheak_arg_exit(char **arg, int *r)
{
	int	i;

	i = 1;
	*r = 1;
	if (arg[1] == NULL)
		return (0);
	else
	{
		if (!is_not_number(arg[1]) && arg[2] != NULL)
		{
			*r = 0;
			printf("exit: too many arguments\n");
			return (1);
		}
		else if (is_not_number(arg[1]))
		{
			printf("exit : %s :numeric argument required\n", arg[1]);
			return (255);
		}
		else
			return (ft_atoi(arg[1]));
	}
	return (1);
}

int	my_exit(char **arg, t_env **env, int k)
{
	int	i;
	int	len;
	int	r;

	len = ft_len_array(arg);
	if (k)
		write(1, "exit\n", 5);
	i = cheak_arg_exit(arg, &r);
	if (r)
		exit(i);
	return (i);
}
