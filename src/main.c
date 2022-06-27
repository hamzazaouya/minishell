#include "../includes/minishell.h"

int main(void)
{
    char str[] = " / || wc -l";
    char **prior = parce_by_prior(str);
    int i = 0;
    while(prior[i])
    {
        printf("%s\n", prior[i]);
        i++;
    }
    while(1);
}