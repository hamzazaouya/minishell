/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 08:26:41 by hazaouya          #+#    #+#             */
/*   Updated: 2022/09/12 08:34:33 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parce_cmd_add_back(t_cmd **cmd_list, t_cmd *cmd)
{
	t_cmd	*temp;

	temp = *cmd_list;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = cmd;
	}
	else
		*cmd_list = cmd;
}

t_cmd	*ft_init_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *) malloc(sizeof(t_cmd));
	cmd->type = 0;
	cmd->cmd = NULL;
	cmd->redire_list = NULL;
	cmd->next = NULL;
	return (cmd);
}

char	*parce_word(t_token *token, char *cmd_value)
{
	char	*sep;
	char	*sep1;
	char	*cmd1;
	char	*cmd2;

	if (!token->value && !cmd_value)
		return (NULL);
	else if (!token->value && data->exit_code == 256)
		return (cmd_value);
	else
	{
		if (!cmd_value)
			cmd_value = (char *) ft_calloc(1, sizeof(char));
		sep = (char *) malloc(sizeof(char) * 2);
		sep[0] = 127;
		sep[1] = 0;
		if (!ft_strlen(token->value) && !ft_strlen(cmd_value))
		{
			sep1 = (char *) malloc(sizeof(char) * 2);
			sep1[0] = ' ';
			sep1[1] = 0;
			cmd1 = ft_strjoin(cmd_value, sep1);
			cmd2 = ft_strjoin(cmd1, sep);
			free(sep1);
		}
		else
		{
			cmd1 = ft_strjoin(cmd_value, token->value);
			cmd2 = ft_strjoin(cmd1, sep);
		}
		free(sep);
		free(cmd1);
		if (cmd_value)
			free(cmd_value);
		return (cmd2);
	}
	return (NULL);
}

t_cmd	*parce_cmd_shell(t_cmd *cmd, t_lexer *lexer, \
		t_token *token, char *cmd_value)
{
	if (token->type == TOKEN_PIPE)
		return (parce_token_pipe_error(cmd, token, 1));
	while (token->type != TOKEN_END && token->type != TOKEN_PIPE)
	{
		if (token->type == TOKEN_WORD)
		{
			cmd_value = parce_word(token, cmd_value);
			if (!cmd_value)
				return (parce_free_cmd(cmd, token, cmd_value));
		}
		else
			if (!parce_redire(cmd, lexer_get_next_token(lexer), token->type))
				return (NULL);
		free_token(&token);
		token = lexer_get_next_token(lexer);
	}
	if (!lexer->c && token->type == TOKEN_PIPE)
		return (parce_token_pipe_error(cmd, token, 0));
	if (token->type == TOKEN_END && !cmd_value && !cmd->redire_list)
		return (parce_free_cmd(cmd, token, cmd_value));
	cmd->cmd = ft_split(cmd_value, 127);
	if (cmd_value)
		free(cmd_value);
	free_token(&token);
	return (cmd);
}

t_cmds	*parce_list_shell(t_lexer *lexer)
{
	t_cmd	*cmd_list;
	t_cmd	*cmd_shell;
	t_cmds	*cmds_list;
	char	*value;

	cmd_list = NULL;
	cmds_list = NULL;
	while (lexer->c)
	{
		value = NULL;
		cmd_shell = parce_cmd_shell(ft_init_cmd(), \
				lexer, lexer_get_next_token(lexer), value);
		if (!cmd_shell)
			return ((t_cmds *) parce_free_cmd_shell(cmd_list));
		else
			parce_cmd_add_back(&cmd_list, cmd_shell);
	}
	if (cmd_list)
	{
		parce_open_redire(cmd_list);
		cmds_list = parce_get_cmds(cmd_list);
		parce_free_cmd_shell(cmd_list);
	}
	return (cmds_list);
}
