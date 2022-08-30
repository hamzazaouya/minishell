#include "../../include/minishell.h"

int type_exist(t_env **env, char *type)
{
    t_env *head;

    head = *env;
    while(head)
    {
        if (ft_strcmp(head->type, type) == 0)
            return (1);
        head = head->next; 
    }
    return (0);
}

void modifier_env(t_env **env, char *type, char *content)
{
    t_env *head;
    char *copy_content;

    head = *env;
    while(head)
    {
        if(ft_strcmp(head->type, type) == 0)
        {
            copy_content = head->content;
            head->content = content;
            free(copy_content);
        }
        head = head->next;
    }
}

void    ajouter_env(t_env **env, char *type, char *content)
{
    t_env *new;

    new = ft_listnew_env(type, content);
    ft_listadd_back_env(env, new);

}

void my_export(char **arg, t_env **env)
{
    char *type;
    char *content;

    //ghanakhad arg li3tani ghanzido f env ila makanch ila kan ghanbadlo 
    //(void)type;
    //(void)content;
    //(void)env;
    while(*arg != NULL)
    {
        type = get_type(*arg);
        //printf("type:%s\n",type);
        content = get_content(*arg);
        //printf("content:%s\n",content);
        if (type_exist(env, type) == 1)
        {
            modifier_env(env, type, content);
            free(type);
        }
        else
        {
            ajouter_env(env,type,content);
        }
        (arg)++;           
    }
}