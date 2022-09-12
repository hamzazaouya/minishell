/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_use_libft.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:48:26 by labenall          #+#    #+#             */
/*   Updated: 2022/09/11 18:48:29 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

t_env	*ft_listnew_env(char *type, char *content)
{
	t_env	*r;

	r = malloc(sizeof(t_env));
	if (r == NULL)
		return (NULL);
	r->type = type;
	r->content = content;
	r->next = NULL;
	return (r);
}

void	ft_listadd_back_env(t_env **list_env, t_env *new)
{
	t_env	*t;

	t = *list_env;
	if (*list_env == NULL)
	{
		*list_env = new;
		return ;
	}
	while (t->next)
		t = t->next;
	t->next = new;
}

int	ft_count_len(unsigned int nbr)
{
	if (nbr < 10)
		return (1);
	return (1 + ft_count_len(nbr / 10));
}

void	ft_itoa_writer(char *result, int nbr_len, unsigned int nbr)
{
	result[nbr_len - 1] = (char)(nbr % 10) + '0';
	if (nbr < 10)
		return ;
	ft_itoa_writer(result, nbr_len - 1, nbr / 10);
}
