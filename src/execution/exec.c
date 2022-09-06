#include "../../include/minishell.h"

void	exec_builtins(t_cmds *cmds, int k)
{
	if(cmds->exec_cmd->type == 0)
		my_cd(cmds->exec_cmd->cmd, &data->list_env);
	else if(cmds->exec_cmd->type == 1)
		my_echo(cmds->exec_cmd->cmd);
	else if(cmds->exec_cmd->type == 2)
		my_env(&data->list_env);
	else if(cmds->exec_cmd->type == 3)
		my_exit(cmds->exec_cmd->cmd, &data->list_env, k);
	else if(cmds->exec_cmd->type == 4)
		my_export(cmds->exec_cmd->cmd, &data->list_env);
	else if(cmds->exec_cmd->type == 5)
		my_pwd();
	else if(cmds->exec_cmd->type == 6)
		my_unset(cmds->exec_cmd->cmd, &data->list_env);
}

int		exec_cmd_len(t_cmds *cmds)
{
	int i;

	i = 0;
	while(cmds)
	{
		i++;
		cmds = cmds->next;
	}
	return (i);
}

void	exec_wait(int	len)
{
	int i;

	i = 0;
	while(i < len)
	{
		wait(NULL);
		i++;
	}
}

void	execute(t_cmds *cmds)
{
	int	end_p;
	int	p[2];
	int	id;
	int	len;

	len = exec_cmd_len(cmds);
	//printf("-->%d\n",len);
	end_p = -1;
	while(cmds)
	{
		if(cmds->next)
			pipe(p);
		
		if (len == 1 && cmds->exec_cmd->type != -1)
			exec_builtins(cmds, 1);
		else
		{
		id = fork();
		if(id == 0)
		{
			signals();
			//signal(SIGINT, proc_signal_handler);
			if(cmds->in_redire > 2)
				dup2(cmds->in_redire, 1);
			if(end_p != -1)
			{
				dup2(end_p, 0);
				close(end_p);
			}
			if(cmds->out_redire > 2)
				dup2(cmds->out_redire, 1);
			if (cmds->next)
			{
				
				dup2(p[1], 1);
				close(p[1]);
			}
			close(p[0]);
			if(cmds->exec_cmd->type != -1)
			{
				exec_builtins(cmds, 0);
				exit(0);
			}
			else
				execve(cmds->exec_cmd->path, cmds->exec_cmd->cmd, data->env);
		}
		else
		{
			if(end_p != -1)
				close(end_p);
			end_p = p[0];
			close(p[1]);
		}
		}
		cmds = cmds->next;
	}
	exec_wait(len);
}