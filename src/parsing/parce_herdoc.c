/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:38:13 by labenall          #+#    #+#             */
/*   Updated: 2022/09/11 22:38:14 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parce.h"

int	parce_child_hedoc(t_redire *redire)
{
	int		check;
	char	*line;

	check = 0;
	close(redire->fd[0]);
	while (1)
	{
		signal(SIGINT, SIG_DFL);
		line = readline("> ");
		if (!line)
			break ;
		check = ft_strcmp(line, redire->value);
		if (check)
		{
			write(redire->fd[1], line, ft_strlen(line));
			write(redire->fd[1], "\n", 1);
		}
		else
			break ;
	}
	close(redire->fd[1]);
	exit(0);
}

void	parce_read_herdoc(t_redire *redire)
{
	int		id;

	pipe(redire->fd);
	id = fork();
	if (id == -1)
	{
		printf("Error in fork\n");
		return ;
	}
	else if (id == 0)
		parce_child_hedoc(redire);
	else
	{
		wait(NULL);
		close(redire->fd[1]);
	}
}

void	parce_open_herdoc(t_cmd *cmds_list)
{
	t_redire	*redire;
	char		c;

	while (cmds_list)
	{
		redire = cmds_list->redire_list;
		while (redire)
		{
			if (redire->type == TOKEN_HERDOC)
				parce_read_herdoc(redire);
			redire = redire->next;
		}
		cmds_list = cmds_list->next;
	}
}
