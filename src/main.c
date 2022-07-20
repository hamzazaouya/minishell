#include "../includes/minishell.h"

int main(void)
{
    char str[] = " ls -la | wc -l || (cat -e | df || ef && (rrt || rtg)) &&lf";
    char **prior = parce_by_prior(str);
    int i = 0;
    while(prior[i])
    {
        printf("%s\n", prior[i]);
        i++;
    }
}