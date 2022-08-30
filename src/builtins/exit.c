#include "../../include/minishell.h"
#include "../../include/builtins.h"

//define my exit


void my_exit(t_env **env)
{
    free_env(env);
    exit(0);
}