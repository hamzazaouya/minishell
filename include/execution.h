#ifndef EXECUTION_H
#define EXECUTION_H
# include "minishell.h"
#include "struct.h"
int	exec_builtins(t_cmds *cmds, int k);
int		exec_cmd_len(t_cmds *cmds);
void	exec_wait(t_cmds *cmds, int	len);
void	execute(t_cmds *cmds);
#endif