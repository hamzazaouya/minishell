#include "../../include/minishell.h"


size_t	ft_strlen(const char *s)
{
	size_t	a;

	if (s == NULL)
		return (0);
	a = 0;
	while (s[a])
		a++;
	return (a);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

char	*ft_strdup(const char *s1)
{
	char	*r;
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen((char *)s1);
	r = malloc(l + 1);
	if (!r)
		return (NULL);
	while (i < l)
	{
		r[i] = s1[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

/*char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	index;
	char	*result;
	//printf("1\n");
	s1_len = ft_strlen(s1);
	//printf("1\n");
	s2_len = ft_strlen(s2);
	//printf("1\n");
	index = 0;
	//printf("index:%zu\n",index);
	result = (char *)malloc((s1_len + s2_len) * sizeof(char) + 1);
	if (!result)
		return (NULL);
	while (index < (s1_len + s2_len))
	{
		if (index < s1_len)
			result[index] = s1[index];
		else
			result[index] = s2[index - s1_len];
		index++;
	}
	result[index] = '\0';
	return (result);
}
*/
char *ft_str(char *type, size_t s)
{
    char    *r;
    size_t  i;

    i = 0;
    r = malloc(s + 1);
    while(i < s)
    {
        r[i] = type[i];
        i++;
    }
    r[i] = 0;
    return (r);
}

int ft_strcmp(char *s1, char *s2)
{
    int i;
   
    /*if (s1 || s2)
        return (0);*/
    i = 0;
    while(s1[i] || s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*s1_holder;
	unsigned char	*s2_holder;

	index = 0;
	s1_holder = (unsigned char *)s1;
	s2_holder = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (index < n && \
			s1_holder[index] == s2_holder[index] && \
			s1_holder[index])
		index++;
	if (index == n)
		return (0);
	return (s1_holder[index] - s2_holder[index]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	size_t	s_len;
	char	*result;

	index = 0;
	s_len = ft_strlen(s);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if ((size_t)start >= s_len)
	{
		result[0] = '\0';
		return (result);
	}
	while (s[index + start] && index < len)
	{
		result[index] = s[index + start];
		index++;
	}
	result[index] = '\0';
	return (result);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*src;

	count = 0;
	src = (unsigned char *)s;
	while (count < n)
	{
		src[count] = c;
		count++;
	}
	return (s);
}

void            *ft_calloc(size_t count, size_t size)
{
	size_t  res_size;
	void    *p;

	res_size = size * count;
	if (!(p = malloc(res_size)))
		return (NULL);
	ft_memset(p, 0, res_size);
	return (p);
}

t_env *ft_listnew_env(char *type,char *content)
{
    t_env   *r;

    r = malloc(sizeof(t_env));
    if (r == NULL)
        return (NULL);
    r->type = type;
    r->content = content;
    r->next = NULL;
    return (r);
}

void    ft_listadd_back_env(t_env **list_env, t_env *new)
{
    t_env	*t;

	t = *list_env;
	if (*list_env == NULL)
	{
		*list_env = new;
		return ;
	}
	while (t->next)
		t = t->next;
	t->next = new;
}
/**** 		itoa 				*****/
static int	ft_count_len(unsigned int nbr)
{
	if (nbr < 10)
		return (1);
	return (1 + ft_count_len(nbr / 10));
}

static void	ft_itoa_writer(char *result, int nbr_len, unsigned int nbr)
{
	result[nbr_len - 1] = (char)(nbr % 10) + '0';
	if (nbr < 10)
		return ;
	ft_itoa_writer(result, nbr_len - 1, nbr / 10);
}

char		*ft_itoa(int n)
{
	unsigned int	n_holder;
	int				negatif;
	int				nbr_len;
	char			*result;

	negatif = 1;
	nbr_len = 0;
	if (n < 0)
	{
		negatif = -1;
		nbr_len = 1;
	}
	n_holder = n * negatif;
	if ((n_holder > 2147483648) || \
		(n_holder > 2147483647 && negatif == 1))
		return (NULL);
	nbr_len += ft_count_len(n_holder);
	result = (char *)malloc((nbr_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_itoa_writer(result, nbr_len, n_holder);
	if (negatif < 0)
		result[0] = '-';
	result[nbr_len] = '\0';
	return (result);
}
/* 			itoa 			********/

void	ft_free_char_array(char **char_array)
{
	int	index;

	index = 0;
	while (char_array[index])
	{
		free(char_array[index]);
		index++;
	}
	if (char_array)
		free(char_array);
	return ;
}