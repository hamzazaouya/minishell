#include "../../include/minishell.h"

void my_env(t_env **env)
{
    t_env   *head;

    head = *env;
    if (env == NULL)
        return ;
    while (head)
    {
        printf("%s=%s\n",head->type,head->content);
        head = head->next;
    }
}