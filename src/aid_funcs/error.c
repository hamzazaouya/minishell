#include <unistd.h>
#include "../../include/minishell.h"

void *single_double_qoute_err(char *value)
{
	free(value);
    write(2, "Error: No Closing qoute\n", ft_strlen("Error: No Closing qoute\n"));
	exit_code = 256;
	return (NULL);
}