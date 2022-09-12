/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 08:16:08 by hazaouya          #+#    #+#             */
/*   Updated: 2022/09/12 08:19:32 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "token.h"
# include "minishell.h"

t_lexer	*init_lexer(char **env, char *contents);
void	lexer_advance(t_lexer *lexer);
void	lexer_skip_whitespace(t_lexer *lexer);
t_token	*lexer_get_next_token(t_lexer *lexer);
t_token	*lexer_collect_string(t_lexer *lexer);
char	*lexer_get_current_char_as_string(t_lexer *lexer);
t_token	*lexer_advance_with_token(t_lexer *lexer, t_token *token);
char	*lexer_collect_expand(t_lexer *lexer);
int		is_word_sep(char c);
t_token	*lexer_token_list(t_lexer *lexer);
void	lexer_return(t_lexer *lexer);
int		is_string_sep(char c);
#endif
