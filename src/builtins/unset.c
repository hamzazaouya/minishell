/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:29:02 by labenall          #+#    #+#             */
/*   Updated: 2022/09/11 16:29:04 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_one_env(t_env *env)
{
	free(env->content);
	free(env->type);
	free(env);
}

void	delete(t_env **env, t_env *del)
{
	t_env	*head;
	t_env	*last;

	head = *env;
	while (head)
	{
		if (ft_strcmp(head->type, del->type) == 0)
		{
			if (head == *env)
			{
				free_one_env(head);
				*env = (*env)->next;
				break ;
			}
			else
			{
				last->next = head->next;
				free_one_env(head);
				break ;
			}
		}
		last = head;
		head = head->next;
	}
}

void	delete_env(t_env **env, char *type)
{
	t_env	*head;

	head = *env;
	while (head)
	{
		if (ft_strcmp(head->type, type) == 0)
			delete(env, head);
		head = head->next;
	}
}

void	my_unset(char **arg, t_env **env)
{
	while (*arg)
	{
		delete_env(env, *arg);
		arg++;
	}
}
