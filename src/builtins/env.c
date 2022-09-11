/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:28:20 by labenall          #+#    #+#             */
/*   Updated: 2022/09/11 16:39:12 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	my_env(t_env **env)
{
	t_env	*head;

	head = *env;
	if (env == NULL)
		return ;
	while (head)
	{
		printf("%s=%s\n", head->type, head->content);
		head = head->next;
	}
}
