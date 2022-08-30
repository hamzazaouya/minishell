#include "../../include/minishell.h"

char *get_content_from_env(t_env *list_env, char *type)
{
    while(list_env)
    {
        //printf("%s\n",list_env->type);
        //printf("%d\n",ft_strcmp(list_env->type, type));
        //printf("%s\n", type);
        if (!ft_strcmp(list_env->type, type))
            return (list_env->content);
        list_env = list_env->next;
    }
    return (NULL);
}


char *get_type(char *type)
{
    char    *r;
    size_t  i;

    i = 0;
    while (type[i] != '=')
        i++;
    r = ft_str(type, i);
    return (r);
}

char *get_content(char *content)
{
    char *r;

    while(*content != '=')
        content++;
    content++;
    //printf("cont: %s\n",content);
    r = NULL;
    r = ft_strdup(content);
    if (r == NULL)
        return (NULL);
    return(r);
}

void init_env(t_env **list_env,char **env)
{
    int i;
    char *type;
    char *content;
    t_env *new;

    i = 0;
    *list_env = NULL;
    while(env[i])
    {
        //printf("env[i]:%s\n",env[i]);
        new = NULL;
        type = NULL;
        type = get_type(env[i]);
        //printf("%s\n",type);
        //printf("ty:%s\n",type);
        content = NULL;
        //printf("get_content:\n");
        content = get_content(env[i]);
        //printf("%s\n",content);
        new = ft_listnew_env(type, content);
        ft_listadd_back_env(list_env, new);
        i++;
    }
}

void    free_env(t_env **list_env)
{
    t_env   *tmp;
    if (list_env != NULL)
    {
        
        while((*list_env))
        {
            //printf("%p\n",*list_env);
            tmp = *list_env;
            //printf("111111111111\n");
            if ((*list_env)->type != NULL)
                free((*list_env)->type);
            (*list_env)->type = NULL;
            //printf("2\n");
            //printf("%s\n",(*list_env)->content);
            if ((*list_env)->content != NULL)
                free((*list_env)->content);
            (*list_env)->content = NULL;
            //(*list_env)->type = NULL;
            //(*list_env)->content = NULL;
            (*list_env) = (*list_env)->next;
            free(tmp);
        }
    }
    //list_env = NULL;
}