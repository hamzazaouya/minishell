/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_aid_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 08:12:26 by hazaouya          #+#    #+#             */
/*   Updated: 2022/09/12 17:08:00 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*lexer_advance_with_token(t_lexer *lexer, t_token *token)
{
	lexer_advance(lexer);
	return (token);
}

char	*lexer_get_current_char_as_string(t_lexer *lexer)
{
	char	*str;

	str = (char *) calloc(2, sizeof(char));
	str[0] = lexer->c;
	str[1] = 0;
	return (str);
}

t_lexer	*init_lexer(char **env, char *contents)
{
	t_lexer	*lexer;

	lexer = calloc(1, sizeof(t_lexer));
	lexer->contents = contents;
	lexer->i = 0;
	lexer->c = contents[lexer->i];
	lexer->env = env;
	return (lexer);
}

void	lexer_advance(t_lexer *lexer)
{
	if (lexer->c)
	{
		lexer->i++;
		lexer->c = lexer->contents[lexer->i];
	}
}

void	lexer_return(t_lexer *lexer)
{
	lexer->i--;
	lexer->c = lexer->contents[lexer->i];
}
