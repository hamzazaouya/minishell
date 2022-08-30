#include "../../include/minishell.h"

char*   get_var_from_env(t_lexer* lexer, char* var_name)
{
    int		i;
	int		var_len;
	char*	value;

    i = 0;
    value = NULL;
    if(var_name)
        var_len = ft_strlen(var_name);
    while(var_name && lexer->env[i])
    {
        if(!ft_strncmp(lexer->env[i], var_name, var_len))
        {
			if(lexer->env[i][var_len] == '=')
            {
                value = (char *) ft_calloc(1, sizeof(char));
				value = ft_strdup(lexer->env[i]+ var_len + 1);
                break;
            }
        }
        i++;
    }
    if(var_name)
	    free (var_name);
    return (value);
}

char    *lexer_get_var_name(t_lexer *lexer)
{
    char    *var_name;
    char    *s;

    var_name = NULL;
    while(ft_isalnum(lexer->c))
    {
        s = lexer_get_current_char_as_string(lexer);
		var_name = ft_collect(var_name, s);
		lexer_advance(lexer);
	}
    return (var_name);
}

char*	lexer_collect_expand(t_lexer *lexer)
{
    char*   var_name;
    char*   value;

    lexer_advance(lexer);
    if (lexer->c == '?')
	{
		lexer_advance(lexer);
		return (ft_itoa(data->exit_code));
	}
    var_name = lexer_get_var_name(lexer);
    
	return (get_content_from_env(data->list_env, var_name));
}