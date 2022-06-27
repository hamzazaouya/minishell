#ifndef MINISHELL_H
#define MINISHELL_H
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include "parsing.h"

char *ft_strtrim_intern(char *str);

typedef struct s_prior_list
{
    char *prior_type;
    char *cmd;
    int *next;
} t_prior;

typedef struct s_cmd
{
    char **command;
} t_cmd;

#endif