#include "../../include/minishell.h"

void	parce_redire_add_back(t_cmd **cmd, t_redire *redire)
{
	t_redire	*temp;

	temp = (*cmd)->redire_list;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = redire;
	}
	else
		(*cmd)->redire_list = redire;
}

t_redire	*parce_init_redire(int type, char *value)
{
	int			len;
	t_redire	*redire;

	redire = (t_redire *) malloc(sizeof(t_redire));
	redire->type = type;
	redire->next = NULL;
	redire->fd[0] = -1;
	redire->fd[1] = -1;
	if (value)
	{
		len = ft_strlen(value);
		redire->value = (char *) malloc(sizeof(char *) * (len + 1));
		ft_strlcpy(redire->value, value, ft_strlen(value) + 1);
	}
	else
		redire->value = NULL;
	return (redire);
}

int	parce_redire(t_cmd *cmd, t_token *token_next, int token_type)
{
	t_redire	*redire;

	if (token_next->type != TOKEN_WORD)
	{
		parce_token_error(cmd, token_next);
		return (0);
	}
	redire = parce_init_redire(token_type, token_next->value);
	parce_redire_add_back(&cmd, redire);
	free_token(&token_next);
	return (1);
}