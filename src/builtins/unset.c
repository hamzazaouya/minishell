#include "../../include/minishell.h"

void    delete(t_env **env, t_env *del)
{
    t_env *head;
    t_env *last;

    head = *env;
    while(head)
    {
        if (ft_strcmp(head->type, del->type) == 0)
        {
            if (head == *env)
            {
                free(head->type);
                free(head->content);
                free(head);
                *env = (*env)->next;
                break ;
            }
            else
            {
                last->next = head->next;
                free(head->type);
                free(head->content);
                free(head);
                break ;
            }
        }
        last = head;
        head = head->next;
    }
}

void delete_env(t_env **env, char *type)
{
    t_env   *head;

    head = *env;
    while (head)
    {
        if(ft_strcmp(head->type, type) == 0)
        {
            delete(env, head);
        }
        head = head->next;
    }
}

void    my_unset(char **arg, t_env **env)
{
    while (*arg)
    {
        delete_env(env, *arg);
        arg++;
    }
}