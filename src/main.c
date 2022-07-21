#include "../includes/minishell.h"

int main(void)
{
    parsing("cat -e  outfile |sssssswc -l (cat -e | df || ef && (rrt || rtg)) && lf && (a && ( a1 || (a2 && b)))");
}

// int sum(int a, int b)
// {
//     return (a + b);
// }

// int sub(int a, int b)
// {
//     return (a - b);
// }

// int mul(int a, int b)
// {
//     return (a * b);
// }


// int main(void)
// {
//     t_cmds *cmds;

//     int (*p[4]) (int x, int y);
//     p[0] = sum;
//     p[1] = sub;
//     p[2] = mul;

//     printf("%d", p[2](10, 20));
// }

// int main(void)
// {
//     char str[] = " ls -la | wc -l || (cat -e | df || ef && (rrt || rtg)) && lf && (a && ( a1 || (a2 && b)))";
//     char **prior = parce_by_prior(str);
//     int i = 0;
//     while(prior[i])
//     {
//         printf("%s\n", prior[i]);
//         i++;
//     }
// }