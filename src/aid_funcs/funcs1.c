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

char **strdup_arr(char **str)
{
	char **arr;
	int len;
	int i;

	i = 0;
	len = ft_len_array(str);
	arr = (char **) malloc(sizeof(char*) * (len + 1));
	while(i < len)
	{
		arr[i] = ft_strdup(str[i]);
		i++;
	}
	arr[i] = 0;
	return (arr);
}