#include "../../include/minishell.h"



int	my_pwd(void)
{
	char	*str;

	str = NULL;
	str = getcwd(str, BUFFER_SIZE);
	if (str == NULL)
	{
		write(1, "cd: An error occured while getting cwd\n", 39);
		return (EXIT_FAILURE);
	}
	else
		printf("%s\n", str);
	free(str);
	return (EXIT_SUCCESS);
}