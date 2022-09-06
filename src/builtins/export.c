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
    int i = 0;
    int j = 0;
    if (s == NULL)
        return NULL;
    while(s[i])
    {
        if ((s[0] == '=' || s[0] == '+') || (s[i] == '+' && s[i + 1] != '='))
        {
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
    }
    r = malloc(i + 1);
    while(j < i)
    {
        r[j] = s[j]; 
        j++;
    }
    r[j] = 0;
    return r;
}

void my_export(char **arg, t_env **env)
{
    char *type = NULL;
    char *content = NULL;
    int k;
    
    int i = 0;
    
    (arg)++;
    i = 0;
    
    if (*arg == NULL)
        printf("declare \n");
    while(*arg != NULL)
    {
        k = 0;
        type = get_type_pro(*arg, &k);
        if (type != NULL)
            content = get_content(*arg);
        if (type != NULL)
        {
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
        (arg)++;
    }
}