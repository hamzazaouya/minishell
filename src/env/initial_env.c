/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:26:37 by labenall          #+#    #+#             */
/*   Updated: 2022/09/11 18:26:39 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_content_from_env(t_env *list_env, char *type)
{
	if(type)
	{
		while (list_env)
		{
			if (!ft_strcmp(list_env->type, type))
				return (ft_strdup(list_env->content));
			list_env = list_env->next;
		}
	}
	return (ft_calloc(1, sizeof(char)));
}

char	*get_type(char *type)
{
	char	*r;
	size_t	i;

	i = 0;
	while (type[i] != '=' && type[i] != '+')
		i++;
	r = ft_str(type, i);
	return (r);
}

char	*get_content(char *content)
{
	char	*r;

	while (*content != '=')
		content++;
	content++;
	r = NULL;
	r = ft_strdup(content);
	if (r == NULL)
		return (NULL);
	return (r);
}

void	init_env(t_env **list_env, char **env)
{
	int		i;
	char	*type;
	char	*content;
	t_env	*new;

	i = 0;
	*list_env = NULL;
	while (env[i])
	{
		new = NULL;
		type = NULL;
		type = get_type(env[i]);
		content = NULL;
		content = get_content(env[i]);
		new = ft_listnew_env(type, content);
		ft_listadd_back_env(list_env, new);
		i++;
	}
}

void	free_env(t_env **list_env)
{
	t_env	*tmp;

	if (list_env != NULL)
	{
		while ((*list_env))
		{
			tmp = *list_env;
			if ((*list_env)->type != NULL)
				free((*list_env)->type);
			(*list_env)->type = NULL;
			if ((*list_env)->content != NULL)
				free((*list_env)->content);
			(*list_env)->content = NULL;
			(*list_env) = (*list_env)->next;
			free(tmp);
		}
	}
	data->env = update_env(list_env);
}
