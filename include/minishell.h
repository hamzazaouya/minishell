#ifndef MINISHELL_H
#define MINISHELL_H
#include "lexer.h"
#include "parce.h"
#include "aid_funcs.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "libft.h"
#include <readline/readline.h>
#include <readline/history.h>
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

int exit_code;

typedef struct s_general {
    int exit_code;
    int cmd_err;
} t_general;

char	*ft_collect(char *s1, char *s2);
#endif