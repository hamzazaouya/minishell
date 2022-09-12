/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 07:54:29 by hazaouya          #+#    #+#             */
/*   Updated: 2022/09/12 08:00:10 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_word_sep(char c)
{
	if (!is_string_sep(c) || c == '\'' || c == '"' || c == '$')
		return (0);
	return (1);
}

char	*lexer_collect_single_quote(t_lexer *lexer)
{
	char	*value;
	char	*s;

	lexer_advance(lexer);
	value = calloc(1, sizeof(char));
	while (lexer->c != 39 && lexer->c)
	{
		s = lexer_get_current_char_as_string(lexer);
		value = ft_collect(value, s);
		lexer_advance(lexer);
	}
	if (!lexer->c)
		return (single_double_qoute_err(value));
	if(!ft_strlen(value))
	{
		free(value);
		value = get_char_as_string(1);
	}
	lexer_advance(lexer);
	return (value);
}

char	*lexer_collect_double_quote(t_lexer *lexer)
{
	char	*value;
	char	*s;

	lexer_advance(lexer);
	value = calloc(1, sizeof(char));
	while (lexer->c != 34 && lexer->c)
	{
		if (lexer->c == '$')
			s = lexer_collect_expand(lexer);
		else
		{
			s = lexer_get_current_char_as_string(lexer);
			lexer_advance(lexer);
		}
		value = ft_collect(value, s);
	}
	if (!lexer->c)
		return (single_double_qoute_err(value));
	lexer_advance(lexer);
	if(!ft_strlen(value))
	{
		free(value);
		value = get_char_as_string(1);
	}
	return (value);
}

char	*lexer_collect_word(t_lexer *lexer)
{
	char	*value;
	char	*s;

	value = calloc(1, sizeof(char));
	while (lexer->c && is_word_sep(lexer->c))
	{
		s = lexer_get_current_char_as_string(lexer);
		value = ft_collect(value, s);
		lexer_advance(lexer);
	}
	return (value);
}

t_token	*lexer_collect_string(t_lexer *lexer)
{
	char	*value;
	char	*s;

	value = NULL;
	while (is_string_sep(lexer->c) && lexer->c)
	{
		if (lexer->c == 34)
			s = lexer_collect_double_quote(lexer);
		else if (lexer->c == 39)
			s = lexer_collect_single_quote(lexer);
		else if (lexer->c == '$')
			s = lexer_collect_expand(lexer);
		else
			s = lexer_collect_word(lexer);
		if(!s)
		{
			if(value)
				free(value);
			return (NULL);
		}
		value = ft_collect(value, s);
	}
	return (init_token(TOKEN_WORD, value));
}
