#include "../../include/minishell.h"



/*char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	index;
	char	*result;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	index = 0;
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
}*/




t_env	*ft_ch_value(t_env *ht, char *key, char *value)
{
	t_env *h;
	char  *old_value;
	h = ht;
	while(h != NULL)
	{
		if (ft_strncmp(h->type, key, ft_strlen(key)) == 0)
		{
			old_value = h->content;
			h->content = ft_strdup(value);
		}
		h = h->next;
	}
	free(old_value);
	return (ht);
	/*t_env	*element;
	char		*value_holder;

	element = ft_get_element(ht, key);
	if (!element)
		return (ht);
	value_holder = element->content;
	if (is_apnd)
		element->content = ft_strjoin(element->content, value);
	else
		element->content = ft_strdup(value);
	free(value_holder);
	return (ht);*/
}


static void	ft_update_pwd(t_env **env, char *old_pwd)
{
	char	*pwd;

	pwd = NULL;
	pwd = getcwd(pwd, BUFFER_SIZE);
	//printf("-1>%s\n",pwd);
	*env = ft_ch_value(*env, "PWD", pwd);
	*env = ft_ch_value(*env, "OLDPWD", old_pwd);
	if (pwd)
		free(pwd);
}

static void	ft_do_cd(char **str_array, t_env **env)
{
	char	*old_pwd;

	old_pwd = NULL;
	old_pwd = getcwd(old_pwd, BUFFER_SIZE);
	//printf("-->%s\n",str_array[1]);
	if (chdir(str_array[1]) == -1)
	{
		if (old_pwd)
			free(old_pwd);
		perror("Minishell: cd: ");
		return ;
	}
	else
	{
		ft_update_pwd(env, old_pwd);
		//ft_update_pwd(env)
	}
	free(old_pwd);
}

static char	*ft_make_err(char **str_array, struct stat **buf)
{
	char		*err_msg;

	err_msg = NULL;
	//printf("-->%s\n",str_array[1]);
	if (!str_array[1])
		err_msg = ft_strdup("please provide a relative or absolute path");
	else if (ft_strlen(str_array[1]) > 255)
		err_msg = ft_strjoin(str_array[1], "file name too long");
	else if (str_array[2] != 0)
		err_msg = ft_strdup("too many arguments");
	else if (access(str_array[1], F_OK) == -1)
		err_msg = ft_strjoin(str_array[1], " No such file or directory");
	else if (lstat((const char *)str_array[1], *buf) == -1)
		err_msg = ft_strdup("Error");
	else if (access(str_array[1], X_OK) == -1)
		err_msg = ft_strjoin("permission denied: ", str_array[1]);
	return (err_msg);
}

static int	ft_check_error(char **str_array)
{
	struct stat	*buf;
	char		*err_msg;

	err_msg = NULL;
	buf = ft_calloc(1, sizeof(struct stat));
	err_msg = ft_make_err(str_array, &buf);
	if (buf)
		free(buf);
	if (err_msg)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(err_msg, 2);
		ft_putstr_fd("\n", 2);
		free(err_msg);
		//exit(1); //l3arbiiii matnsach
		
		return (1);
	}
	return (0);
}

int	my_cd(char **str_array, t_env **env)
{
	/*int i = 0;
	while(str_array[i])
	{
		printf("%s \n",str_array[i]);
		i++;
	}*/
	if (str_array[1] == NULL)
	{	
		str_array[1] = get_content_from_env(*env, "HOME");
		str_array[2] = NULL;
	}

	/*i = 0;
	while(str_array[i])
	{
		printf("%s \n",str_array[i]);
		i++;
	}*/
	if (ft_check_error(str_array))
		return (1);
	ft_do_cd(str_array, env);
	return (0);
}