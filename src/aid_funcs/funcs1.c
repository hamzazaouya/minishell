#include "../../include/minishell.h"

char	*ft_collect(char *s1, char *s2)
{
	char *value;

	if(!s2)
		return (s1);
	else if(!s1)
		s1 = (char *) calloc(1, sizeof(char));
	value = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (value);
}

char	*char_as_string(char c)
{
	char *str;

	str = (char *) malloc(sizeof(char) * 1);
	str[0] = c;
	str[1] = 0;
	return (str);
}