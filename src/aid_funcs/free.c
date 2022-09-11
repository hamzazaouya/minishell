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
        // printf("it NULL\n");
        while(str[i])
        {
            // printf("__before free str[i]\n");
             free(str[i++]);
            // printf("__after free str[i]\n");
        }
        // printf("-->before free str\n");
        // free(str);
        // printf("-->after free str\n");
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
        // printf("-1\n");
        free_arry_of_chars(temp1->exec_cmd->cmd);
        // printf("0\n");
        free(temp1->exec_cmd->path);
        // printf("1\n");
        free(temp1->exec_cmd);
        temp2 = temp1;
        temp1 = temp1->next;
        // printf("2\n");
        free(temp2);
    }
}