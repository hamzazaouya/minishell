/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:27:59 by labenall          #+#    #+#             */
/*   Updated: 2022/09/11 16:28:02 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env	*ft_ch_value(t_env *ht, char *key, char *value)
{
	t_env	*h;
	char	*old_value;

	h = ht;
	while (h != NULL)
	{
		if (ft_strncmp(h->type, key, ft_strlen(key)) == 0)
		{
			old_value = h->content;
			h->content = ft_strdup(value);
		}
		h = h->next;
	}
	if (old_value)
	{
		old_value = NULL;
		free(old_value);
	}
	return (ht);
}

static void	ft_update_pwd(t_env **env, char *old_pwd)
{
	char	*pwd;

	pwd = NULL;
	pwd = getcwd(pwd, BUFFER_SIZE);
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
		free(old_pwd);
	}
}

static char	*ft_make_err(char **str_array, struct stat **buf)
{
	char		*err_msg;

	err_msg = NULL;
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
		return (1);
	}
	return (0);
}

int	my_cd(char **str_array, t_env **env)
{
	char **my_array;

	if (str_array[1] == NULL)
	{	
		my_array = malloc(sizeof(char *) * 3);
		my_array[0] = ft_strdup("cd");
		my_array[1] = ft_strdup(get_content_from_env(*env, "HOME"));
		my_array[2] = NULL;
		ft_do_cd(my_array, env);
		free_arry_of_chars(my_array);
	}
	else
	{
		if (ft_check_error(str_array))
			return (1);
		ft_do_cd(str_array, env);
	}
	return (0);
}
