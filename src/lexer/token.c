/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 07:35:20 by hazaouya          #+#    #+#             */
/*   Updated: 2022/09/12 17:09:40 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_string_sep(char c)
{
	if (c == '>' || c == '<' || c == '|' || c == ' ' || c == '\t')
		return (0);
	return (1);
}

t_token	*init_token(int type, char *value)
{
	t_token	*token;

	token = (t_token *) calloc(1, sizeof(t_token));
	token->type = type;
	if (value)
		token->value = ft_strdup(value);
	if (value)
		free(value);
	return (token);
}
