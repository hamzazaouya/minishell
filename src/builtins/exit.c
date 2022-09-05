#include "../../include/minishell.h"
#include "../../include/builtins.h"

//define my exit
int is_not_number(char *s)
{
    int i;

    i = 0;
    if (s == NULL)
        return 0;
    while(s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (1);
        i++;
    }
    return 0;
}

void my_exit(char **arg, t_env **env, int k)
{
    int i;
    int len;

    len = ft_len_array(arg);
    if (k)
        write(1, "exit\n", 5);
    if (len > 2)
    {
        printf("exit: too many arguments\n");
        exit(0);
    }
    if (arg[1] == NULL)
        i = 0;
    else
        i = ft_atoi(arg[1]);

    if (is_not_number(arg[1]))
    {
        printf("exit : %s :numeric argument required\n", arg[1]);
        i = 0;
    }
    exit(i);
}
//mli katkon exit m3a pipe mkaytktabch exit 
void exit_in_chlid(char **arg, t_env **env)
{
    int i;
    int len;

    len = ft_len_array(arg);
    if (len > 2)
    {
        printf("exit: too many arguments\n");
        exit(0);
    }
    if (arg[1] == NULL)
        i = 0;
    else
        i = ft_atoi(arg[1]);
    if (is_not_number(arg[1]))
    {
        printf("exit : %s :numeric argument required\n", arg[1]);
        i = 0;
    }
    exit(i);
}