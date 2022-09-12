/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:42:01 by labenall          #+#    #+#             */
/*   Updated: 2022/09/12 17:15:21 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parce.h"

t_exec_cmd	*parce_cmd_exec_init(t_cmd *cmd_list)
{
	t_exec_cmd	*cmd_exec;

	if (!cmd_list->cmd)
		return (NULL);
	cmd_exec = (t_exec_cmd *) malloc(sizeof(t_exec_cmd));
	cmd_exec->cmd = strdup_arr(cmd_list->cmd);
	cmd_exec->type = parce_check_cmd_type(cmd_list->cmd[0]);
	if (cmd_exec->type != -1)
		cmd_exec->path = NULL;
	else
	{
		cmd_exec->path = parce_get_cmd_path(cmd_list);
	}
	return (cmd_exec);
}

int	parce_get_initred(t_redire *redire)
{
	int	fd;

	fd = -1;
	while (redire)
	{
		if (redire->type == TOKEN_INF || redire->type == TOKEN_HERDOC)
		{
			if (fd != -1)
				close(fd);
			fd = redire->fd[0];
		}
		redire = redire->next;
	}
	return (fd);
}

int	parce_get_outred(t_redire *redire)
{
	int	fd;

	fd = -1;
	while (redire)
	{
		if (redire->type == TOKEN_APPEND || redire->type == TOKEN_OUTF)
		{
			if (fd != -1)
				close(fd);
			fd = redire->fd[0];
		}
		redire = redire->next;
	}
	return (fd);
}

t_cmds	*parce_copy_cmds(t_cmd *cmd_list)
{
	t_cmds	*cmds;

	cmds = parce_get_cmds_init();
	cmds->exec_cmd = parce_cmd_exec_init(cmd_list);
	cmds->type = cmd_list->type;
	cmds->in_redire = parce_get_initred(cmd_list->redire_list);
	cmds->out_redire = parce_get_outred(cmd_list->redire_list);
	return (cmds);
}

t_cmds	*parce_get_cmds(t_cmd *cmd_list)
{
	t_cmds	*cmds_list;
	t_cmds	*cmds;
	t_cmd	*tmp;

	tmp = cmd_list;
	cmds_list = NULL;
	while (cmd_list)
	{
		cmds = parce_copy_cmds(cmd_list);
		parce_cmds_add_back(&cmds_list, cmds);
		cmd_list = cmd_list->next;
	}
	return (cmds_list);
}
