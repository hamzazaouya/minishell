#include "../../include/parce.h"

void	parce_read_herdoc(t_redire *redire)
{
	int		check;
	char	*line;

	check = 0;
	//signals();
    pipe(redire->fd);
	while (1)
	{
		line = readline("> ");
		if(!line)
			break;
		//Signal ctrl-
		
		check = ft_strcmp(line, redire->value);
		if (check)
        {
			write(redire->fd[1], line, ft_strlen(line));
			write(redire->fd[1], "\n", 1);
        }
		else
			break ;
        free(line);
	}
    free(line);
	close(redire->fd[1]);
}

void    parce_open_herdoc(t_cmd *cmds_list)
{
	t_redire	*redire;
    char        c;
    while(cmds_list)
	{
		redire = cmds_list->redire_list;
		while(redire)
		{
			
			if(redire->type == TOKEN_HERDOC)
				parce_read_herdoc(redire);
			redire = redire->next;
		}
		cmds_list = cmds_list->next;
	}
}