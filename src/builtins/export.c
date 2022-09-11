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
    if (!s[i])
        return (NULL);
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

int cheak_arg(char **arg)
{
    int i;
    int j;

    i = 0;
    (arg)++;
    while(arg[i])
    {
        // printf("arg[i]->%s\n",arg[i]);
        j = 0;
        while (arg[i][j] != '=')
        {
            // printf("==>%c\n",arg[i][j]);
            // printf("in while will\n");
            if (arg[i][j] == '\0')
                return 0;
            // printf("is alpha:%d,is dejit%d\n",ft_isalpha(arg[i][j]),ft_isdigit(arg[i][j]));
            if ((j == 0 && (!ft_isalpha(arg[i][j]) && !(arg[i][j] == '_'))) || (j != 0 && (!ft_isdigit(arg[i][j]) && !ft_isalpha(arg[i][j])) && !(arg[i][j] == '+') && !(arg[i][j] == '_')))
            {
                // printf("j=>%d\n",j);
                // printf("export: `%s': not a valid identifier\n",arg[i]);
                return 1;
            }
            j++;
            //sleep(1);
        }
        // printf("arg===>%s\n",arg[i]);
        i++;
    }
    return 0;
}

int size_of_list(t_env *env)
{
    int i;

    i = 0;
    while(env)
    {
        i++;
        env = env->next;
    }
    return (i);
}

char **update_env(t_env **env)
{
    t_env *h_env;
    char *tmp1;
    h_env = *env;
    int len_env = size_of_list(h_env);
    // printf("len %d\n",len_env);
    char **r;
    int i;

    i = 0;
    r = malloc(sizeof(char *) * len_env);
    while(h_env)
    {
        // printf("1\n");
        
        r[i] = ft_strjoin("", h_env->type);
        tmp1 = r[i];
        r[i] = ft_strjoin(r[i], "=");
        free(tmp1);
        tmp1 = r[i];
        r[i] = ft_strjoin(r[i], h_env->content);
        free(tmp1);
        h_env = h_env->next;
        i++;
    }
    r[i] = NULL;
    //  printf("before free\n");
    //free_arry_of_chars(data->env);
    //print_array_str(r);
    //  printf("after free\n");
    return (r);
}
void ft_free_env(char **holder)
{
    int i;

    i = 0;
    if (holder != NULL)
    {
        if (holder[i] != NULL)
            free(holder[i]);
        i++;
        free(holder);
    }

}
int my_export(char **arg, t_env **env)
{
    char *type = NULL;
    char *content = NULL;
    int k;
    int r;
    char **copy_arg = arg;
    
    
    int i = 0;
    
    (arg)++;
    i = 0;
    
    if (*arg == NULL)
    {
        declare_print(*env);
        return (0);
    }
    //  printf("before cheak\n");
    if (cheak_arg(copy_arg) == 1)
            return 1;
    // printf("after cheak\n");
    //sleep(5);
    // printf("arg:%s\n",*arg);
    while(*arg != NULL)
    {
        k = 0;
        type = get_type_pro(*arg, &k);
        //  printf("type:%s\n",type);
        if (type != NULL)
        {
            content = get_content_pro(*arg);
            //printf("get_cont%s\n",content);

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
    // printf("before update\n");
    char **holder = data->env;
    data->env= update_env(env);
    ft_free_env(holder);
    // printf("after update\n");
    //my_env(env);
    //printf("-------------------------->\n");
    //print_array_str(data->env);
    //printf("-------------------------->\n");
    return (0);
}