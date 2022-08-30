# ifndef PARCE_H
# define PARCE_H
# include "minishell.h"
# include "lexer.h"
#include "struct.h"



t_cmd   *parce_free_cmd_shell(t_cmd *cmd);
t_cmd   *parce_free_cmd(t_cmd *cmd, t_token *token, char *value);
t_cmd	*parce_token_pipe_error(t_cmd *cmd, t_token *token,int sign);
t_cmd	*parce_list_shell(t_lexer *lexer);
t_cmd	*free_cmd_shell(t_cmd *cmd, t_token *token);
void	parce_token_error(t_cmd *cmd , t_token *token);
#endif