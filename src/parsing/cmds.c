#include "../../include/parce.h"

t_exec_cmd *parce_cmd_exec_init(char **cmd, char *path)
{
    t_exec_cmd *cmd_exec;

    cmd_exec = (t_exec_cmd *) malloc(sizeof(t_exec_cmd));
    cmd_exec->cmd = cmd;
    cmd_exec->path = path;
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
    cmds->exec_cmd = parce_cmd_exec_init(cmd_list->cmd, NULL); //parce_cmd_path(cmd_list->cmd[0]
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

    while(cmd_list)
    {
        cmds = parce_copy_cmds(cmd_list);
        parce_cmds_add_back(&cmds_list, cmds);
        cmd_list = cmd_list->next;
    }
    return (cmds_list);
}