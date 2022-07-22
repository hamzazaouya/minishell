#include "../../includes/minishell.h"

int ft_cmd_len(char **cmd_sep, int i)
{
    int j;

    j = 0;
    while(cmd_sep[i + j] && ft_strncmp(cmd_sep[i + j], "|", 1))
    {
        j++;
    }
    return (j);
}

char **ft_get_cmd(char **cmd_sep, int i)
{
    char **cmd;
    int len;
    int j;

	
	j = 0;
	len = ft_cmd_len(cmd_sep, i);
    cmd = (char **)malloc(sizeof(char *) * (len + 1));
    while(j < len)
    {
        cmd[j] = cmd_sep[i + j];
        j++;
    }
	cmd[j] = NULL;
    return (cmd);
}

int cmd_type(char **cmd)
{
    int i;

    i = 0;
    while(cmd[i])
    {
        if(!ft_strncmp(cmd[i], "<", ft_strlen(cmd[i])))
            return (0);
        else if (!ft_strncmp(cmd[i], ">", ft_strlen(cmd[i])))
            return (1);
        else if(!ft_strncmp(cmd[i], "<<", ft_strlen(cmd[i])))
            return (2);
        else if(!ft_strncmp(cmd[i], ">>", ft_strlen(cmd[i])))
            return (3);
		i++;
    }
	return (4);
}

int	next_cmd(char **cmd_sep, int i)
{
	while(cmd_sep[i] && !ft_strncmp(cmd_sep[i], "|", ft_strlen(cmd_sep[i])))
		i++;
	if(cmd_sep[i])
		i++;
	return (i);
}

void	creat_cmd_list(t_cmds **cmd_list, char **cmd)
{
	// t_cmds	*node;
	// int		type;
	// t_cmds	*(*f[5])(char **cmd);

	// type = cmd_type(cmd);
	herdoc(cmd);
}

void    parsing(char *str)
{
	char	**cmd_sep;
	char	**cmd;
    t_cmds	*cmd_list;
	int		i;

	i = 0;
	cmd_sep = separation(str);
    while(cmd_sep[i])
    {
        printf("%s\n", cmd_sep[i]);
        i++;
    }
	// while(cmd_sep[i])
	// {
	// 	cmd = ft_get_cmd(cmd_sep, i);
	// 	creat_cmd_list(&cmd_list, cmd);
	// 	i = next_cmd(cmd_sep, i);
	// }
    // cmd = ft_get_cmd(cmd_sep, i);
    // creat_cmd_list(&cmd_list, cmd);
}