#ifndef LEXER_H
#define LEXER_H
#include "token.h"
#include "minishell.h"

typedef struct	s_lexer
{
	char			c;
	unsigned int	i;
	char			*contents;
	char			**env;
}	t_lexer;

t_lexer*	init_lexer(char **env, char *contents);
void		lexer_advance(t_lexer *lexer);
void		lexer_skip_whitespace(t_lexer* lexer);
t_token*	lexer_get_next_token(t_lexer* lexer);
t_token*	lexer_collect_string(t_lexer* lexer);
char*		lexer_get_current_char_as_string(t_lexer* lexer);
t_token*	lexer_advance_with_token(t_lexer* lexer, t_token* token);
char		*lexer_collect_expand(t_lexer *lexer);
int			is_word_sep(char c);
t_token*	lexer_token_list(t_lexer *lexer);
#endif