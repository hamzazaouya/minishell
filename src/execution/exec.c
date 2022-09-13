/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:01:53 by hazaouya          #+#    #+#             */
/*   Updated: 2022/09/12 17:05:06 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_child(t_cmds *cmds, int *end_p, int *p)
{
	if (cmds->in_redire > 2)
		dup2(cmds->in_redire, 0);
	else if (*end_p != -1)
	{
		dup2(*end_p, 0);
		close(*end_p);
	}
	if (cmds->out_redire > 2)
		dup2(cmds->out_redire, 1);
	else if (cmds->next)
		dup2(p[1], 1);
	close(p[1]);
	close(p[0]);
	if (cmds->exec_cmd->type != -1)
		exit(exec_builtins(cmds, 0));
	else
		execve(cmds->exec_cmd->path, cmds->exec_cmd->cmd, data->env);
}

void	exec_parent(t_cmds *cmds, int *end_p, int *p)
{
	data->signal = 0;
	if (*end_p != -1)
		close(*end_p);
	*end_p = p[0];
	close(p[1]);
	if (cmds->in_redire > 2)
		close(cmds->in_redire);
	if (cmds->out_redire > 2)
		close(cmds->out_redire);
}

int	exec_with_break(t_cmds *cmds, int *p)
{
	t_cmds	*tmp;
	int		end_p;
	int		id;

	tmp = cmds;
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
			return (id);
		}
		else if (id == 0)
			exec_child(cmds, &end_p, p);
		else
			exec_parent(cmds, &end_p, p);
	}
	return (0);
}

void	exec_cmds(t_cmds *cmds, int *p)
{
	int	id;

	while (cmds)
	{
		id = exec_with_break(cmds, p);
		if (id == -1)
			break ;
		cmds = cmds->next;
	}
}

void	execute(t_cmds *cmds)
{
	int	end_p;
	int	p[2];

	end_p = -1;
	exec_cmds(cmds, p);
	exec_wait(cmds, exec_cmd_len(cmds));
}
