#include "../../include/minishell.h"

int	ft_echo_n(char *src)
{
	int	i;

	if (!src)
		return (0);
	i = 0;
	if (src[i] == '-')
	{
		i++;
		if (src[i] != 'n')
			return (0);
		while (src[i] == 'n')
			i++;
	}
	if (src[i] == 0)
		return (1);
	return (0);
}

void	my_echo(char **src)
{
	int	i;
	int	n;
	int	count;

	n = 0;
	i = 1;

	// int j = 0;
	// printf("-----\n");
	// while (src[j])
	// {
	// 	printf("%s\n",src[j]);
	// 	j++;
	// }
	// printf("-----\n");
	
	while (ft_echo_n(src[i]))
	{
		n = 1;
		i++;
	}
	count = i;
	while (src[count])
		count++;
	while (src[i])
	{
		printf("%s", src[i]);
		i++;
		if (i != count)
			printf(" ");
	}
	if (n == 0)
		printf("\n");
}

/*int main(int ac, char **av)
{
	my_echo(&av[1]);
	return 0;
}*/