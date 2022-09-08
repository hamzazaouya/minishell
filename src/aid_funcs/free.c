#include "../../include/minishell.h"

void   free_token(t_token **token)
{
    if((*token)->value)
    {
        free((*token)->value);
    }
    free(*token);
}

void    free_arry_of_chars(char **str)
{
    int i;

    i = 0;
    if (str != NULL)
    {
        while(str[i])
            free(str[i++]);
        free(str);
    }
}