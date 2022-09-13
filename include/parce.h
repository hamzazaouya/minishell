/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:15:27 by labenall          #+#    #+#             */
/*   Updated: 2022/09/12 23:15:30 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCE_H
# define PARCE_H
# include "minishell.h"
# include "lexer.h"
# include "struct.h"

void	*parce_free_cmd_shell(t_cmd *cmd);
t_cmd	*parce_free_cmd(t_cmd *cmd, t_token *token, char *value);
t_cmd	*parce_token_pipe_error(t_cmd *cmd, t_token *token, int sign);
t_cmds	*parce_list_shell(t_lexer *lexer);
t_cmd	*free_cmd_shell(t_cmd *cmd, t_token *token);
void	parce_token_error(t_cmd *cmd, t_token *token);
void	parce_open_herdoc(t_cmd *cmd_shell);
void	parce_open_redire(t_cmd *cmd_shell);
t_cmds	*parce_get_cmds(t_cmd *cmd_list);
int		parce_redire(t_cmd *cmd, t_token *token_next, int token_type);
void	parce_cmds_add_back(t_cmds **cmds_list, t_cmds *cmds);
t_cmds	*parce_get_cmds_init(void);
char	*parce_get_cmd_path(t_cmd *cmd_list);
int		parce_check_cmd_type(char *cmd);
char	*get_char_as_string(char c);
t_cmd	*ft_init_cmd(void);

#endif
