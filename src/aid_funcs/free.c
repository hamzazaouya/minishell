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

void    free_cmds_list(t_cmds **cmds)
{
    t_cmds *temp1;
    t_cmds *temp2;

    temp1 = *cmds;
    temp2 = temp1;
    while(temp1)
    {
        free_arry_of_chars(temp1->exec_cmd->cmd);
        free(temp1->exec_cmd->path);
        temp2 = temp1;
        temp1 = temp1->next;
        free(temp2);
    }
}