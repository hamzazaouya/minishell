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

void concatiner(t_env **env, char *type, char *content)
{
    t_env *head;
    char *copy_content;

    head = *env;
    while(head)
    {
        if(ft_strcmp(head->type, type) == 0)
        {
            copy_content = head->content;
            head->content = ft_strjoin(copy_content, content);
            free(copy_content);
            free(content);
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
char *get_type_pro(char *s, int *k)
{
    char *r;
    size_t i = 0;
    int j = 0;
    if (s == NULL)
        return NULL;
    while(s[i])
    {
        if ((s[0] >= '0' & s[0] <= '9') || s[i] == '-' || (s[i] == '+' && s[i + 1] != '='))
        {
            // printf("caractere >%c\n",s[i]);
            printf("export: `%s': not a valid identifier\n",s);
            return (NULL);
        }
        if (s[i] == '=' || s[i] == '+')
        {
            if (s[i] == '+')
                *k = 1;
            break;
        }
        i++;
        // printf("i==>%zu\n",i);
    }
    r = ft_str(s, i);
    //printf("r==>%s\n",r);
    return r;
}

void    declare_print(t_env *env)
{
    while(env)
    {
        printf("declare -x %s=%s\n",env->type,env->content);
        env = env->next;
    }
}

char *get_content_pro(char *arg)
{
    int i;
    char *content;

    content = NULL;
    i = 0;
    while(arg[i])
    {
        if (arg[i] == '=')
            break;
        i++;
    }
    if (arg[i] == '=')
    {
        arg = arg + i + 1;
        content = ft_strdup(arg);
    }
    else
        content = ft_strdup("");
    return (content);
}
int my_export(char **arg, t_env **env)
{
    char *type = NULL;
    char *content = NULL;
    int k;
    int r;
    
    int i = 0;
    
    (arg)++;
    i = 0;
    
    if (*arg == NULL)
    {
        declare_print(*env);
        return (0);
    }
    while(*arg != NULL)
    {
        /*if (cheak_arg(arg) == 1) 
            return 1;*/
        k = 0;
        type = get_type_pro(*arg, &k);
        if (type != NULL)
        {
            content = get_content_pro(*arg);
            // printf("get_cont%s\n",content);

            if (type_exist(env, type) == 1)
            {
                if (k == 0)
                    modifier_env(env, type, content);
                else
                    concatiner(env, type, content);
                free(type);
            }
            else
            {
                ajouter_env(env,type,content);
            }
        }
        else
            return (1);
        (arg)++;

    }
    return (0);
}