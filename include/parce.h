# ifndef PARCE_H
# define PARCE_H
# include "minishell.h"
# include "lexer.h"

typedef struct s_redire
{
    int     fd;
    int     type;
    char    *value;
    struct s_redire *next;
}   t_redire;

typedef struct s_cmd
{
    int         type;
    char        **cmd;
	t_redire    *redire_list;
    struct s_cmd   	*next;
}   t_cmd;

typedef struct s_exec_cmd
{
    char    **cmd;
    char    *path;
} t_exec_cmd;

typedef struct s_cmd_shell
{
    int         type;
    int         in_redire;
    int         out_redire;
    t_exec_cmd *exec_cmd;
    struct  s_cmd_shell *next;
}   t_cmd_shell;

t_cmd   *parce_free_cmd_shell(t_cmd *cmd);
t_cmd   *parce_free_cmd(t_cmd *cmd, t_token *token, char *value);
t_cmd	*parce_token_pipe_error(t_cmd *cmd, t_token *token,int sign);
t_cmd	*parce_list_shell(t_lexer *lexer);
t_cmd	*free_cmd_shell(t_cmd *cmd, t_token *token);
void	parce_token_error(t_cmd *cmd , t_token *token);
#endif