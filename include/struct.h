#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_env
{
    char *type;
    char *content;
    struct s_env *next;
}               t_env;

typedef struct token_struct
{
    enum
    {
        TOKEN_INF,
        TOKEN_HERDOC,
        TOKEN_OUTF,
        TOKEN_APPEND,
        TOKEN_WORD,
        TOKEN_PIPE,
        TOKEN_END,
    } type;
    char *value;
} t_token;

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

typedef struct s_data
{
    int     exit_code;
    t_env	*list_env;
}   t_data;

#endif