#ifndef MINISHELL_H
#define MINISHELL_H
#include "lexer.h"
#include "parce.h"
#include "env.h"
#include "builtins.h"
#include "aid_funcs.h"
# include <term.h>


# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
#include "libft.h"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

int exit_code;

typedef struct s_general {
    int exit_code;
    int cmd_err;
} t_general;

char	*ft_collect(char *s1, char *s2);
#endif