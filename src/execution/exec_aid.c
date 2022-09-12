/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_aid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:05:18 by hazaouya          #+#    #+#             */
/*   Updated: 2022/09/12 17:06:57 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec_builtins(t_cmds *cmds, int k)
{
	int	r;

	r = 0;
	if (cmds->exec_cmd->type == 0)
		r = my_cd(cmds->exec_cmd->cmd, &data->list_env);
	else if (cmds->exec_cmd->type == 1)
		my_echo(cmds->exec_cmd->cmd);
	else if (cmds->exec_cmd->type == 2)
		my_env(&data->list_env);
	else if (cmds->exec_cmd->type == 3)
		r = my_exit(cmds->exec_cmd->cmd, &data->list_env, k);
	else if (cmds->exec_cmd->type == 4)
		r = my_export(cmds->exec_cmd->cmd, &data->list_env);
	else if (cmds->exec_cmd->type == 5)
		my_pwd();
	else if (cmds->exec_cmd->type == 6)
		my_unset(cmds->exec_cmd->cmd, &data->list_env);
	return (r);
}

int	exec_cmd_len(t_cmds *cmds)
{
	int	i;

	i = 0;
	while (cmds)
	{
		i++;
		cmds = cmds->next;
	}
	return (i);
}

void	exec_wait(t_cmds *cmds, int len)
{
	int		i;
	int		status;
	t_cmds	*tmp;

	status = 0;
	i = 0;
	tmp = cmds;
	while (tmp->next)
		tmp = tmp->next;
	while (i < len)
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
