/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:28:44 by labenall          #+#    #+#             */
/*   Updated: 2022/09/11 17:12:16 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_type_pro(char *s, int *k)
{
	char	*r;
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (help_type_pro(s, k, &i) == 0)
		return (NULL);
	if (!s[i])
		return (NULL);
	r = ft_str(s, i);
	return (r);
}

void	declare_print(t_env *env)
{
	while (env)
	{
		printf("declare -x %s=%s\n", env->type, env->content);
		env = env->next;
	}
}

char	*get_content_pro(char *arg)
{
	int		i;
	char	*content;

	content = NULL;
	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
			break ;
		i++;
	}
	if (arg[i] == '=')
	{
		arg = arg + i + 1;
		content = ft_strdup(arg);
	}
	else
		content = ft_strdup("");
	return (content);
}

int	cheak_arg(char **arg)
{
	int	i;
	int	j;

	i = 0;
	(arg)++;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j] != '=')
		{
			if (arg[i][j] == '\0')
				return (0);
			if ((j == 0 && (!ft_isalpha(arg[i][j]) && !(arg[i][j] == '_'))) \
			|| (j != 0 && (!ft_isdigit(arg[i][j]) && !ft_isalpha(arg[i][j])) \
			&& !(arg[i][j] == '+') && !(arg[i][j] == '_')))
			{
				printf("export: `%s': not a valid identifier\n", arg[i]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	size_of_list(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}
