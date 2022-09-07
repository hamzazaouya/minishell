#include "../../include/parce.h"

char    *parce_expand_herdoc(char *line)
{
    int i;

    i = 0;
    while(line[i])
    {
        
    }
}

void	parce_read_herdoc(t_redire *redire)
{
	int		check;
	char	*line;

	check = 0;
    pipe(redire->fd);
	while (1)
	{
		line = readline("> ");
		if(!line)
			break;
		check = ft_strncmp(line, redire->value, \
				ft_strlen(redire->value));
		//line = 
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