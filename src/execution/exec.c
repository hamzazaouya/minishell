#include "../../include/minishell.h"

int	exec_builtins(t_cmds *cmds, int k)
{
	int r;

	r = 0;
	if(cmds->exec_cmd->type == 0)
		r = my_cd(cmds->exec_cmd->cmd, &data->list_env);
	else if(cmds->exec_cmd->type == 1)
		my_echo(cmds->exec_cmd->cmd);
	else if(cmds->exec_cmd->type == 2)
		my_env(&data->list_env);
	else if(cmds->exec_cmd->type == 3)
		r = my_exit(cmds->exec_cmd->cmd, &data->list_env, k);
	else if(cmds->exec_cmd->type == 4)
		r = my_export(cmds->exec_cmd->cmd, &data->list_env);
	else if(cmds->exec_cmd->type == 5)
		my_pwd();
	else if(cmds->exec_cmd->type == 6)
		my_unset(cmds->exec_cmd->cmd, &data->list_env);
	return (r);
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

void	exec_wait(t_cmds *cmds, int	len)
{
	int i;
	int status;
	t_cmds *tmp;

	status = 0;
	i = 0;
	tmp = cmds;
	while (tmp->next)
		tmp = tmp->next;
	while(i < len)
	{
		wait(&status);
		if (WIFEXITED(status))
			data->exit_code = WEXITSTATUS(status);
		if (status == 2)
			data->exit_code = 130;
		if (status == 3)
			data->exit_code = 131;
		i++;
	}
	if (tmp->type)
		data->exit_code = tmp->type;
}

void	exec_child(t_cmds *cmds, int *end_p, int *p)
{
	if(cmds->in_redire > 2)
		dup2(cmds->in_redire, 0);
	else if(*end_p != -1)
	{
		dup2(*end_p, 0);
		close(*end_p);
	}
	if(cmds->out_redire > 2)
		dup2(cmds->out_redire, 1);
	else if (cmds->next)
		dup2(p[1], 1);
	close(p[1]);
	close(p[0]);

	if(cmds->exec_cmd->type != -1)
		exit(exec_builtins(cmds, 0));
	else
		execve(cmds->exec_cmd->path, cmds->exec_cmd->cmd, data->env);
}

void	exec_parent(t_cmds *cmds,int *end_p, int *p)
{
	data->signal = 0;
	if(*end_p != -1)
		close(*end_p);
	*end_p = p[0];
	close(p[1]);
	if(cmds->in_redire > 2)
		close(cmds->in_redire);
	if(cmds->out_redire > 2)
		close(cmds->out_redire);
}

int		exec_with_break(t_cmds *cmds, int *p)
{
	t_cmds *tmp;
	int		end_p;
	int 	id;

	if (cmds->next)
			pipe(p);
	if (exec_cmd_len(tmp) == 1 && cmds->exec_cmd && cmds->exec_cmd->type != -1)
		cmds->type = exec_builtins(cmds, 1);
	else if (!cmds->type)
	{
		id = fork();
		if (id == -1)
		{
			printf("Error in fork\n");
			return(id);
		}
		else if (id == 0)
			exec_child(cmds, &end_p, p);
		else
			exec_parent(cmds, &end_p, p);
	}
	return (0);
}
// old_signal[0] = signal(SIGINT, sigint_handler_in_process);
			// old_signal[1] = signal(SIGQUIT, sigquit_handler_in_process);

void	exec_cmds(t_cmds *cmds, int *p)
{
	int 	id;

	while (cmds)
	{
		id = exec_with_break(cmds, p);
		if(id == -1)
			break ;
		cmds = cmds->next;
	}
}

void	execute(t_cmds *cmds)
{
	int	end_p;
	int	p[2];
	// sig_t old_signal[2];

	end_p = -1;
	exec_cmds(cmds, p);
	exec_wait(cmds, exec_cmd_len(cmds));
	// signal(SIGINT, old_signal[0]);
	// signal(SIGQUIT, old_signal[1]);
}