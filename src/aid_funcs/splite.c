#include "../../include/minishell.h"

static int	char_is_sep(char c, char sep)
{
	int	i;

	i = 0;
	if (c == sep || c == '\0')
		return (1);
	return (0);
}

static void	write_word(char *dest, char *from, char sep)
{
	int	i;

	i = 0;
	while (char_is_sep(from[i], sep) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static	int	cancel(char **s, int w)
{
	while (w > 0)
	{
		free(s[w]);
		w--;
	}
	return (0);
}

static int	write_split(char **split, char *str, char sep)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_is_sep(str[i], sep) == 1)
			i++;
		else
		{
			j = 0;
			while (char_is_sep(str[i + j], sep) == 0)
				j++;
			split[word] = ((char *)malloc(j + 1));
			if (!split[word])
				return (cancel(split, word));
			write_word(split[word], str + i, sep);
			i += j;
			word++;
		}
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	char	*str;
	int		words;
	int		i;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_is_sep(str[i + 1], c) == 1 \
				&& char_is_sep(str[i], c) == 0)
			words++;
		i++;
	}
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res[words] = 0;
	if (write_split(res, str, c) == 0)
		return (NULL);
	return (res);
}