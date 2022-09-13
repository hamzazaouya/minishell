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

char	**update_env(t_env **env)
{
	t_env	*h_env;
	char	*tmp1;
	int		i;
	char	**r;
	int		len_env;

	h_env = *env;
	i = 0;
	len_env = size_of_list(h_env);
	r = malloc(sizeof(char *) * len_env);
	while (h_env)
	{
		r[i] = ft_strjoin("", h_env->type);
		tmp1 = r[i];
		r[i] = ft_strjoin(r[i], "=");
		free(tmp1);
		tmp1 = r[i];
		r[i] = ft_strjoin(r[i], h_env->content);
		free(tmp1);
		h_env = h_env->next;
		i++;
	}
	r[i] = NULL;
	return (r);
}

void	ft_free_env(char **holder)
{
	int	i;

	i = 0;
	if (holder != NULL)
	{
		if (holder[i] != NULL)
			free(holder[i]);
		i++;
		free(holder);
	}
}

int	changer_env(char *arg, t_env **env)
{
	int		k;
	char	*type;
	char	*content;

	type = NULL;
	content = NULL;
	k = 0;
	type = get_type_pro(arg, &k);
	if (type != NULL)
	{
		content = get_content_pro(arg);
		if (type_exist(env, type) == 1)
		{
			if (k == 0)
				modifier_env(env, type, content);
			else
				concatiner(env, type, content);
			free(type);
		}
		else
			ajouter_env(env, type, content);
	}
	else
		return (1);
	return (0);
}

int	help_export(char **arg, t_env **env)
{
	char	*type;
	char	*content;
	int		k;

	type = NULL;
	content = NULL;
	while (*arg != NULL)
	{
		if (changer_env(*arg, env) == 1)
			return (1);
		(arg)++;
	}
	return (0);
}

int	my_export(char **arg, t_env **env)
{
	int		r;
	char	**copy_arg;
	int		i;
	char	**holder;

	copy_arg = arg;
	(arg)++;
	i = 0;
	if (*arg == NULL)
	{
		declare_print(*env);
		return (0);
	}
	if (cheak_arg(copy_arg) == 1)
		return (1);
	if (help_export(arg, env) == 1)
		return (1);
	holder = data->env;
	data->env = update_env(env);
	ft_free_env(holder);
	return (0);
}
