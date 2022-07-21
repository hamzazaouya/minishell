#include "../../includes/minishell.h"

int is_prior(char *str)
{
    if((*str == '|' && *(str + 1) == '|') || (*str == '&' && *(str + 1) == '&'))
        return 1;
    return 0;
}

int move_to_end(char *str, int prenth_num)
{
    int *prenth;
    int i;
    int j;

    i = 0;
    j = 0;
    prenth = (int *) calloc(prenth_num, sizeof(int));
    while(str[j])
    {
        if(str[j] == '(')
            prenth[i++] = '(';
        else if(str[j] == ')')
            prenth[i--] = 0;
        j++;
        if(i == 0)
            break ;
    }
    return (j);
}

int get_prenth_num(char *str)
{
    int i;
    int ctr;

    i = 0;
    ctr = 0;
    while(*str)
    {
        if(*str == '(')
            ctr++;
        str++;
    }
    return ctr;
}

int get_prior_num(char *str)
{
    int i;
    int ctr;
    int prenth_num;

    i = 0;
    ctr = 0;
    prenth_num = get_prenth_num(str);
    while(str[i])
    {
        if(str[i] == '(')
            i += move_to_end(str + i, prenth_num);
        if(is_prior(str + i))
        {
            ctr++;
            i++;
        }
        i++;
    }
    return ctr;
}

int get_cmd_len(char *str)
{
    int i;
    int prenth_num;

    i = 0;
    prenth_num = get_prenth_num(str);
    while(!is_prior(str + i) && str[i])
    {
        if(str[i] == '(')
            i += move_to_end(str + i, prenth_num);
        i++;
    }
    return (i--);
}

char *get_prior(char *str, int *i)
{
    char *prior;

    prior = (char *) malloc(sizeof(char) * 3);
    prior[0] = str[(*i)++];
    prior[1] = str[(*i)++];
    prior[2] = 0;
    return (prior);
}

char    *get_prior_cmd(char *str, int *i)
{
    int cmd_len;
    char *cmd;
    int j;

    j = 0;
    cmd_len = get_cmd_len(str);
    cmd = (char *) malloc(sizeof(char) + (cmd_len + 1));
    while(j < cmd_len)
    {
        cmd[j] = str[j];
        j++;
        (*i)++;
    }
    cmd[j] = 0;
    return (cmd);
}

char **parce_by_prior(char *str)
{
    char **prior;
    int     prior_num;
    int     i;
    int     j;
    i = 0;
    j = 0;
    str = ft_strtrim(str, " ", 0);
    prior = (char **) malloc(sizeof(char *) * ((get_prior_num(str) * 2 + 1) + 1));
    while(str[i])
    {
        prior[j] = get_prior_cmd(str + i, &i);
        prior[j] = ft_strtrim(prior[j], " ", 1);
        if(is_prior(str + i))
            prior[++j] = get_prior(str, &i);
        j++;
    }
    free(str);
    prior[j] = NULL;
    return (prior);
}