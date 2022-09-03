#include "../../include/parce.h"

char	*parce_get_cmd_with_path(char *cmd)
{
	int		checker;

	checker = 1;
	checker = access(cmd, X_OK);
    if(!checker)
        return (ft_strdup(cmd));
    perror(cmd);
	return (NULL);
}

char*	parce_cmd_without_path(char *cmd)
{
	int		i;
	int		checker;
    char    **paths;
	char	*path;

	i = 0;
    paths = ft_split(get_content_from_env(data->list_env, "PATH"), ':');
	while (paths[i])
	{
        path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, cmd);
		checker = access(path, X_OK);
		if (!checker)
			break ;
		free (path);
        path = NULL;
		i++;
	}
    if(!path)
    {
        write(2, "command not found\n", ft_strlen("command not found\n"));
		data->exit_code = 127;
    }
    free(paths);
	return (path);
}

char    *parce_get_cmd_path(char *cmd)
{
    char *check;
    char *path;

    check = ft_strchr(cmd, '/');
    if(check)
        path = parce_get_cmd_with_path(cmd);
    else
        path = parce_cmd_without_path(cmd);
    return (path);
}

int parce_check_cmd_type(char *cmd)
{
    if(!ft_strncmp(cmd, "cd", ft_strlen(cmd)))
        return (0);
    else if(!ft_strncmp(cmd, "echo",ft_strlen(cmd)))
        return (1);
    else if(!ft_strncmp(cmd, "env", ft_strlen(cmd)))
        return (2);
    else if(!ft_strncmp(cmd, "exit",ft_strlen(cmd)))
        return (3);
    else if(!ft_strncmp(cmd, "export", ft_strlen(cmd)))
        return (4);
    else if(!ft_strncmp(cmd, "pwd", ft_strlen(cmd)))
        return (5);
    else if(!ft_strncmp(cmd, "unset", ft_strlen(cmd)))
        return (6);
    return (-1);
}

t_exec_cmd *parce_cmd_exec_init(char **cmd)
{
    t_exec_cmd *cmd_exec;

    cmd_exec = (t_exec_cmd *) malloc(sizeof(t_exec_cmd));
    cmd_exec->cmd = cmd;
    cmd_exec->type = parce_check_cmd_type(cmd[0]);
    if(cmd_exec->type != -1)
        cmd_exec->path = NULL;
    else
        cmd_exec->path = parce_get_cmd_path(cmd[0]);
    return (cmd_exec);
}

t_cmds *parce_get_cmds_init(void)
{
    t_cmds *cmds;

    cmds = (t_cmds *) malloc(sizeof(t_cmds));
    cmds->type = 0;
    cmds->exec_cmd = NULL;
    cmds->in_redire = -1;
    cmds->out_redire = -1;
    cmds->next = NULL;
    return (cmds);
}

int parce_get_initred(t_redire *redire)
{
    int fd;

    fd = -1;
    while(redire)
    {
        if(redire->type == TOKEN_INF || redire->type == TOKEN_HERDOC)
        {
            if(fd != -1)
                close(fd);
            fd = redire->fd[0];
        }
        redire = redire->next;
    }
    return (fd);
}

int parce_get_outred(t_redire *redire)
{
    int fd;

    fd = -1;
    while (redire)
    {
        if(redire->type == TOKEN_APPEND || redire->type == TOKEN_OUTF)
        {
            if(fd != -1)
                close(fd);
            fd = redire->fd[0];
        }
        redire = redire->next;
    }
    return (fd);
}

t_cmds *parce_copy_cmds(t_cmd *cmd_list)
{
    t_cmds *cmds;

    cmds = parce_get_cmds_init();
    cmds->type = cmd_list->type;
    cmds->exec_cmd = parce_cmd_exec_init(cmd_list->cmd);
    if(cmds->exec_cmd->type == -1 && !cmds->exec_cmd->path)
        cmds->type = 1;
    cmds->in_redire = parce_get_initred(cmd_list->redire_list);
    cmds->out_redire = parce_get_outred(cmd_list->redire_list);
    return (cmds);
}

void	parce_cmds_add_back(t_cmds **cmds_list,t_cmds *cmds)
{
	t_cmds *temp;

	temp = *cmds_list;
	if (temp)
	{
		while(temp->next)
			temp = temp->next;
		temp->next = cmds;
	}
	else
		*cmds_list = cmds;
}

t_cmds  *parce_get_cmds(t_cmd *cmd_list)
{
    t_cmds  *cmds_list;
    t_cmds  *cmds;

    cmds_list = NULL;
    while(cmd_list)
    {
        cmds = parce_copy_cmds(cmd_list);
        parce_cmds_add_back(&cmds_list, cmds);
        cmd_list = cmd_list->next;
    }
    return (cmds_list);
}