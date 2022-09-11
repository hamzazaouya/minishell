/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_redire.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:33:35 by labenall          #+#    #+#             */
/*   Updated: 2022/09/11 22:33:37 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parce_open_files(t_redire *redire)
{
	while (redire)
	{
		if (!redire->value)
		{
			write(2, "ambiguous redirect\n", ft_strlen("ambiguous redirect\n"));
			return (1);
		}
		if (redire->type == TOKEN_INF)
			redire->fd[0] = open(redire->value, O_RDONLY, 0644);
		else if (redire->type == TOKEN_OUTF)
		{
			redire->fd[0] = open(redire->value, \
				O_RDWR | O_CREAT | O_TRUNC, 0644);
		}
		else if (redire->type == TOKEN_APPEND)
			redire->fd[0] = open(redire->value, \
				O_RDWR | O_CREAT | O_APPEND, 0644);
		if (redire->fd[0] == -1)
		{
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			write(2, "\n", 1);
			return (1);
		}
		redire = redire->next;
	}
	return (0);
}

void	parce_open_redire(t_cmd *cmds_list)
{
	int		check;
	t_cmd	*temp;

	temp = cmds_list;
	parce_open_herdoc(cmds_list);
	while (temp)
	{
		if (temp->redire_list)
		{
			check = parce_open_files(temp->redire_list);
			if (check)
				temp->type = check;
		}
		temp = temp->next;
	}
}
