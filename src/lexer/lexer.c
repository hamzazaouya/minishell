#include "../../include/minishell.h"
// #include "../include/lexer.h"
// #include "../include/parce.h"

t_lexer*	init_lexer(char **env, char *contents)
{
	t_lexer* lexer = calloc(1, sizeof(t_lexer));
	lexer->contents = contents;
	lexer->i = 0;
	lexer->c = contents[lexer->i];
	lexer->env = env;
	return (lexer);
}

void		lexer_advance(t_lexer *lexer)
{
	if(lexer->c)
	{
		lexer->i++;
		lexer->c = lexer->contents[lexer->i];
	}
}

void		lexer_return(t_lexer *lexer)
{
	lexer->i--;
	lexer->c = lexer->contents[lexer->i];
}

void		lexer_skip_whitespace(t_lexer* lexer)
{
	while((lexer->c == ' ' && lexer->c) || (lexer->c == '\t' && lexer->c))
		lexer_advance(lexer);
}

int	lexer_char_looker(t_lexer* lexer, char c)
{
	lexer_advance(lexer);
	if(lexer->c == c)
		return (1);
	lexer_return(lexer);
	return (0);
}

t_token*	lexer_parce_outfile(t_lexer* lexer)
{
	
	if(lexer_char_looker(lexer, '>'))
		return (lexer_advance_with_token(lexer, init_token(TOKEN_APPEND, lexer_get_current_char_as_string(lexer))));
	return	(lexer_advance_with_token(lexer, init_token(TOKEN_OUTF, lexer_get_current_char_as_string(lexer))));
}

t_token*	lexer_parce_infile(t_lexer* lexer)
{
	if(lexer_char_looker(lexer, '<'))
		return (lexer_advance_with_token(lexer, init_token(TOKEN_HERDOC, lexer_get_current_char_as_string(lexer))));
	return	(lexer_advance_with_token(lexer, init_token(TOKEN_INF, lexer_get_current_char_as_string(lexer))));
}

t_token*	lexer_get_next_token(t_lexer* lexer)
{
	t_token	*token;

	token = NULL;
	while(lexer->c)
	{
		if (lexer->c == ' ' || lexer->c == '\t')
			lexer_skip_whitespace(lexer);
		if (lexer->c == '>')
			return (lexer_parce_outfile(lexer));
		else if (lexer->c == '<')
			return (lexer_parce_infile(lexer));
		else if (lexer->c == '|')
			return (lexer_advance_with_token(lexer, init_token(TOKEN_PIPE, lexer_get_current_char_as_string(lexer))));
		else if (lexer->c)
			return (lexer_collect_string(lexer));
	}
	token = (t_token *) calloc(1, sizeof(t_token));
	token->type = TOKEN_END;
	token->value = NULL;
	return (token);
}

t_token*		lexer_advance_with_token(t_lexer* lexer, t_token* token)
{
	lexer_advance(lexer);
	return (token);
}

char*		lexer_get_current_char_as_string(t_lexer* lexer)
{
	char*	str = (char *) calloc(2, sizeof(char));
	str[0] = lexer->c;
	str[1] = 0;
	return (str);
}