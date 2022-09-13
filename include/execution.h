/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:22:07 by labenall          #+#    #+#             */
/*   Updated: 2022/09/12 23:22:09 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# include "minishell.h"
# include "struct.h"

int		exec_builtins(t_cmds *cmds, int k);
int		exec_cmd_len(t_cmds *cmds);
void	exec_wait(t_cmds *cmds, int len);
void	execute(t_cmds *cmds);

#endif
