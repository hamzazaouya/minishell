#include "../../include/minishell.h"

void   free_token(t_token **token)
{
    if((*token)->value)
    {
        free((*token)->value);
    }
    free(*token);
}