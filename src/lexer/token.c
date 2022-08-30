#include "../../include/minishell.h"

t_token	*init_token(int type, char *value)
{
	t_token* token = (t_token*) calloc(1, sizeof(t_token));
	token->type = type;
	if(value)
		token->value = ft_strdup(value);
	if(value)
		free(value);
	return (token);
}