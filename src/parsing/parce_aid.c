/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_aid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:41:40 by hazaouya          #+#    #+#             */
/*   Updated: 2022/09/12 17:41:59 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parce.h"

void	parce_cmds_add_back(t_cmds **cmds_list, t_cmds *cmds)
{
	t_cmds	*temp;

	temp = *cmds_list;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = cmds;
	}
	else
		*cmds_list = cmds;
}

t_cmds	*parce_get_cmds_init(void)
{
	t_cmds	*cmds;

	cmds = (t_cmds *) malloc(sizeof(t_cmds));
	cmds->type = 0;
	cmds->exec_cmd = NULL;
	cmds->in_redire = -1;
	cmds->out_redire = -1;
	cmds->next = NULL;
	return (cmds);
}

t_cmd	*ft_init_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *) malloc(sizeof(t_cmd));
	cmd->type = 0;
	cmd->cmd = NULL;
	cmd->redire_list = NULL;
	cmd->next = NULL;
	return (cmd);
}

char	*get_char_as_string(char c)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = 0;
	return (str);
}
