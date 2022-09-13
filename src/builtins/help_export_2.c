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

int	type_exist(t_env **env, char *type)
{
	t_env	*head;

	head = *env;
	while (head)
	{
		if (ft_strcmp(head->type, type) == 0)
			return (1);
		head = head->next;
	}
	return (0);
}

void	modifier_env(t_env **env, char *type, char *content)
{
	t_env	*head;
	char	*copy_content;

	head = *env;
	while (head)
	{
		if (ft_strcmp(head->type, type) == 0)
		{
			copy_content = head->content;
			head->content = content;
			free(copy_content);
		}
		head = head->next;
	}
}

void	concatiner(t_env **env, char *type, char *content)
{
	t_env	*head;
	char	*copy_content;

	head = *env;
	while (head)
	{
		if (ft_strcmp(head->type, type) == 0)
		{
			copy_content = head->content;
			head->content = ft_strjoin(copy_content, content);
			free(copy_content);
			free(content);
		}
		head = head->next;
	}
}

void	ajouter_env(t_env **env, char *type, char *content)
{
	t_env	*new;

	new = ft_listnew_env(type, content);
	ft_listadd_back_env(env, new);
}

int	help_type_pro(char *s, int *k, size_t *i)
{
	while (s[*i])
	{
		if ((s[0] >= '0' & s[0] <= '9') || s[*i] == '-'
			|| (s[*i] == '+' && s[*i + 1] != '=')
			|| (s[0] == '=' && s[1] == 0)
			|| (s[0] == '=' && s[1] == '=')
			|| (s[0] == '+' && s[1] == '='))
		{
			printf("export: `%s': not a valid identifier\n", s);
			return (0);
		}
		if (s[*i] == '=' || s[*i] == '+')
		{
			if (s[*i] == '+')
				*k = 1;
			break ;
		}
		(*i)++;
	}
	return (1);
}
