#include "../../include/parce.h"

void	free_cmd_args(char **args)
{
	int i;

	i = 0;
	while(args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	free_cmd_redire(t_redire *redire)
{
	t_redire *temp1;
    t_redire *temp2;

    temp1 = redire;
    while(temp1)
    {
        temp2 = temp1;
        temp1 = temp1->next;
        free(temp2);
    }
}

t_cmd  *parce_free_cmd(t_cmd *cmd, t_token *token, char *value)
{
	if(cmd->redire_list)
		free_cmd_redire(cmd->redire_list);
	if(cmd->cmd)
		free_cmd_args(cmd->cmd);
    if(value)
        free(value);
    if(cmd)
        free(cmd);
	if(token)
    	free_token(&token);
    return (NULL);
}

t_cmd *parce_free_cmd_shell(t_cmd *cmd)
{
	t_cmd *temp1;
	t_cmd *temp2;

	temp1 = cmd;
	while(temp1)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		parce_free_cmd(temp2, NULL, NULL);
	}
	return (NULL);
}

t_cmd	*parce_token_pipe_error(t_cmd *cmd, t_token *token,int sign)
{
	int len;

	if(sign)
	{
		len = ft_strlen("syntax error near unexpected token '|'\n");
		write(2, "syntax error near unexpected token '|'\n", len);
	}
	else
	{
		len = ft_strlen("syntax error near unexpected token 'newline'\n");
		write(2, "syntax error near unexpected token 'newline'\n", len);
	}
	data->exit_code = 258;
	return (parce_free_cmd(cmd, token, NULL));
}


void    parce_token_error(t_cmd *cmd , t_token *token)
{
	write(2, "syntax error near unexpected token '", ft_strlen("syntax error near unexpected token '"));
	if(!token->value)
		write(2, "newline", ft_strlen("newline"));
	else
		write(2, token->value, ft_strlen(token->value));
	write(2, "'\n", 2);
	data->exit_code = 258;
}