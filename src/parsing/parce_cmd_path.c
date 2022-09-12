/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_cmd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:42:10 by hazaouya          #+#    #+#             */
/*   Updated: 2022/09/12 18:30:38 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parce.h"

char	*parce_get_cmd_with_path(char *cmd)
{
	int		checker;

	checker = 1;
	checker = access(cmd, X_OK);
	if (!checker)
		return (ft_strdup(cmd));
	perror(cmd);
	return (NULL);
}

char	*parce_get_path(t_cmd *cmd_list, char **paths)
{
	int		i;
	char	*path;
	int		checker;

	i = 0;
	while (paths[i])
	{
		path = ft_collect(ft_strdup(paths[i]), ft_strdup("/"));
		path = ft_collect(path, ft_strdup(cmd_list->cmd[0]));
		checker = access(path, X_OK);
		if (!checker)
			break ;
		free (path);
		path = NULL;
		i++;
	}
	return (path);
}

char	*parce_cmd_without_path(t_cmd *cmd_list)
{
	int		i;
	int		checker;
	char	**paths;
	char	*path;

	i = 0;
	path = get_content_from_env(data->list_env, "PATH");
	if (!path)
	{
		ft_putstr_fd("No such file or directory\n", 2);
		cmd_list->type = 127;
		return (NULL);
	}
	paths = ft_split(path, ':');
	free(path);
	parce_get_path(cmd_list, paths);
	if (!path)
	{
		write(2, "command not found\n", ft_strlen("command not found\n"));
		cmd_list->type = 127;
	}
	free_arry_of_chars(paths);
	return (path);
}

char	*parce_get_cmd_path(t_cmd *cmd_list)
{
	char	*check;
	char	*path;

	check = ft_strchr(cmd_list->cmd[0], '/');
	if (check)
		path = parce_get_cmd_with_path(cmd_list->cmd[0]);
	else
	{
		path = parce_cmd_without_path(cmd_list);
	}
	return (path);
}

int	parce_check_cmd_type(char *cmd)
{
	if (!ft_strcmp(cmd, "cd"))
		return (0);
	else if (!ft_strcmp(cmd, "echo"))
		return (1);
	else if (!ft_strcmp(cmd, "env"))
		return (2);
	else if (!ft_strcmp(cmd, "exit"))
		return (3);
	else if (!ft_strcmp(cmd, "export"))
		return (4);
	else if (!ft_strcmp(cmd, "pwd"))
		return (5);
	else if (!ft_strcmp(cmd, "unset"))
		return (6);
	return (-1);
}
