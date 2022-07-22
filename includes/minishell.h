#ifndef MINISHELL_H
#define MINISHELL_H
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include "parsing.h"
#include "libft/libft.h"

char *ft_strtrim_intern(char *str);

typedef struct s_prior_list
{
    char *prior_type;
    char *cmd;
    int *next;
} t_prior;

typedef struct s_cmds
{
    char			**command;
    int				in_f;
	int				out_f;
	char            **delimtr;
    char            **file_name;
	struct s_cmds 	*next;
} t_cmds;

t_cmds	*ft_lstnew(void);
char	**separation(char *str);
void    parsing(char *str);
t_cmds  *ft_lstnew(void);
t_cmds  *herdoc(char **cmd);

#endif