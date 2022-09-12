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

int	ft_len_array(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_str(char *type, size_t s)
{
	char	*r;
	size_t	i;

	i = 0;
	r = malloc(s + 1);
	while (i < s)
	{
		r[i] = type[i];
		i++;
	}
	r[i] = 0;
	return (r);
}

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

static int	ft_count_len(unsigned int nbr)
{
	if (nbr < 10)
		return (1);
	return (1 + ft_count_len(nbr / 10));
}

static void	ft_itoa_writer(char *result, int nbr_len, unsigned int nbr)
{
	result[nbr_len - 1] = (char)(nbr % 10) + '0';
	if (nbr < 10)
		return ;
	ft_itoa_writer(result, nbr_len - 1, nbr / 10);
}

char	*ft_itoa(int n)
{
	unsigned int	n_holder;
	int				negatif;
	int				nbr_len;
	char			*result;

	negatif = 1;
	nbr_len = 0;
	if (n < 0)
	{
		negatif = -1;
		nbr_len = 1;
	}
	n_holder = n * negatif;
	if ((n_holder > 2147483648) || \
		(n_holder > 2147483647 && negatif == 1))
		return (NULL);
	nbr_len += ft_count_len(n_holder);
	result = (char *)malloc((nbr_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_itoa_writer(result, nbr_len, n_holder);
	if (negatif < 0)
		result[0] = '-';
	result[nbr_len] = '\0';
	return (result);
}

void	ft_free_char_array(char **char_array)
{
	int	index;

	index = 0;
	while (char_array[index])
	{
		free(char_array[index]);
		index++;
	}
	if (char_array)
		free(char_array);
	return ;
}
