#ifndef BUILTINS_H
#define BUILTINS_H

#define BUFFER_SIZE 100

#include "struct.h"


void    my_env(t_env **env);
void	my_echo(char **src);
int		my_pwd(void);
int     my_cd(char **str_array, t_env **env);
void    my_export(char **arg, t_env **env);
void    my_unset(char **arg, t_env **env);
void    my_exit(t_env **env);
#endif