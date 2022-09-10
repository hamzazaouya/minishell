#include "../../include/minishell.h"
#include "../../include/builtins.h"
#include "limits.h"

//define my exit
static	int	cas(int s, int *r)
{
    *r = 1;
	if (s == 1)
		return (-1);
	else
		return (0);
}

static int	invalid_number(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		i++;
	}
    return 0;
}

int	ft_atoi_pro(const char *str,int  *r)
{
	int						s;
	unsigned long long		res;
	unsigned long long		stock;

	s = 1;
	res = 0;
    *r = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	else if (*str == '+')
		str++;
    if (invalid_number(str) == -1)
	    return (-1);
	while (*str >= '0' && *str <= '9')
	{
		stock = res;
		res = res * 10 + *str - '0';
		if (s == 1 && (stock > res || res > LONG_MAX))
			return (cas(s, r));
        else if (s == -1 && (stock > res || (s * res  < (LONG_MIN))))
        {
            //printf("lib9a f namra:%s\n",str);
            //printf ("im here\n");
            return (cas(s, r));
        }
		str++;
	}
	return (s * res);
}

int is_not_number(char *s)
{
    int i;
    int n;
    int r;

    i = 0;
    if (s == NULL)
        return 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    while(s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (1);
        i++;
    }
    n = ft_atoi_pro(s, &r);
    if (r)
        return 1;
    else
        return 0;
}

int cheak_arg_exit(char **arg, int *r)
{
    int i;
    
    i = 1;
    *r = 1;
    if (arg[1] == NULL)
    {
        return 0;
    }
    else
    {
        if (!is_not_number(arg[1]) && arg[2] != NULL)
        {
            *r = 0;
            printf("exit: too many arguments\n");
            return 1;
        }
        else if (is_not_number(arg[1]))
        {
            printf("exit : %s :numeric argument required\n", arg[1]);
            return (255);
        }
        else
        {
            return (ft_atoi(arg[1]));
        }
    }
    return (1);
}

int my_exit(char **arg, t_env **env, int k)
{
    int i;
    int len;
    int r;
    len = ft_len_array(arg);
    if (k)
        write(1, "exit\n", 5);
    i = cheak_arg_exit(arg, &r);
    /*if (r == 0)
    {
        printf("exit: too many arguments\n");
        //exit(1);
    }*/
    /*if (arg[1] == NULL)
        i = 0;
    else
        i = ft_atoi(arg[1]);

    if (is_not_number(arg[1]))
    {
        printf("exit : %s :numeric argument required\n", arg[1]);
        i = 255;
    }*/
    //printf("--%d\n",r);
    if (r)
        exit(i);
    return (i);
}
//mli katkon exit m3a pipe mkaytktabch exit 
/*void exit_in_chlid(char **arg, t_env **env)
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
}*/