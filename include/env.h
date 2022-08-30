#ifndef ENV_H
#define ENV_H
#include <stdlib.h>
#include "minishell.h"
#include "struct.h"


void init_env(t_env **list_env,char **env);
char *get_content_from_env(t_env *list_env, char *type);
void    free_env(t_env **list_env);
char *get_content(char *content);
char *get_type(char *type);

t_env *ft_listnew_env(char *type,char *content);
void    ft_listadd_back_env(t_env **list_env, t_env *new);

int ft_strcmp(char *s1, char *s2);
char *ft_str(char *type, size_t s);
#endif
