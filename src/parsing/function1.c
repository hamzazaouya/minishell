#include "../../includes/minishell.h"

int     infl_cmd_len(char **p_cmd, char *inf_typ)
{
    int i;

    i = 0;
    while(p_cmd[i])
    {
        if(!ft_strncmp(p_cmd[i], inf_typ, ft_strlen(p_cmd[i])))
            i += 2;
        else
            i++;
    }
    return (i);
}

char    **infile_cmd(char **p_cmd, char *inf_typ)
{
    char    **cmd;
    int     i;
    int     j;

    i = 0;
    j = 0;
    cmd = (char **) malloc(sizeof(char *) * (infl_cmd_len(p_cmd, inf_typ) + 1));
    while(p_cmd[i])
    {
        if(!ft_strncmp(p_cmd[i], inf_typ, ft_strlen(p_cmd[i])))
            i += 2;
        else
        {
			cmd[j] = (char *) malloc(sizeof(char) * (ft_strlen(p_cmd[i]) + 1));
			ft_strlcpy(cmd[j], p_cmd[i], ft_strlen(p_cmd[i]) + 1);
            j++;
            i++;
        }
    }
    cmd[j] = NULL;
    return (cmd);
}

char *infile_name(char **p_cmd, char *inf_typ)
{
	int	i;
	char *file_name;

	i = 0;
	while(ft_strncmp(p_cmd[i], inf_typ, ft_strlen(p_cmd[i])))
		i++;
	file_name = (char *) malloc(sizeof(char) * (ft_strlen(p_cmd[++i]) + 1));
	ft_strlcpy(file_name, p_cmd[i], (ft_strlen(p_cmd[i]) + 1));
	return (file_name);
}

t_cmds *herdoc(char **cmd)
{
    t_cmds *new_cmd;

    new_cmd = ft_lstnew();
    new_cmd->command = infile_cmd(cmd, "<<");
	new_cmd->delimtr = infile_name(cmd, "<<");
	new_cmd->in_f = 0;
	new_cmd->out_f = -2;
    int i = 0;
    while(new_cmd->command[i])
    {
        printf("%s\n", new_cmd->command[i]);
        i++;
    }
	printf("+++%s\n", new_cmd->delimtr);
    return (new_cmd);
}

// t_cmds *herdoc(char **cmd)
// {
// 	t_cmds *new_cmd;

// 	new_cmd = ft_lstnew();
// 	new_cmd->command = infile_cmd(cmd, "<");
// 	new_cmd->file_nm = infile_name(cmd, "<");
// 	new_cmd->in_f = open();
// 	new_cmd->out_f = -2;
// }