#ifndef AID_FUNCS_H
#define AID_FUNCS_H

#include "struct.h"

void    free_token(t_token **token);
void	*single_double_qoute_err(char *value);
void    free_arry_of_chars(char **str);
char	*char_as_string(char c);
int     ft_len_array(char **s);
void    free_cmds_list(t_cmds **cmds);

#endif