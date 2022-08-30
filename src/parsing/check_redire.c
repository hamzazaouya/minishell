#include "../../include/minishell.h"

void	parce_read_herdoc(t_redire **redire)
{
	
}

t_cmd   *parce_open_herdoc(t_cmd *cmd_shell)
{
	t_redire	*redire;

    while(cmd_shell)
	{
		redire = cmd_shell->redire_list;
		while(redire)
		{
			if(redire->type = TOKEN_HERDOC)
				parce_read_herdoc(&redire);
			redire = redire->next;
		}
		cmd_shell = cmd_shell->next;
	}
}

t_cmd   *parce_open_cmd_redire(t_cmd *cmd_shell)
{
    
}