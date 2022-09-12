/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:10:20 by labenall          #+#    #+#             */
/*   Updated: 2022/09/11 22:10:28 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/minishell.h"
#include "../include/lexer.h"
#include "../include/parce.h"

/*void preter_first_list(t_cmd *cmd_list)
{
    int i;

    while(cmd_list)
    {
        i = 0;
        while(cmd_list->cmd && cmd_list->cmd[i])
            printf("\"%s\", \n", cmd_list->cmd[i++]);
        while(cmd_list->redire_list)
        {
            printf("type = %d, value = %s, fd = %d\n",cmd_list->redire_list->type, cmd_list->redire_list->value, cmd_list->redire_list->fd[0]);
            cmd_list->redire_list = cmd_list->redire_list->next;
        }
        printf("-------------\n");
        cmd_list = cmd_list->next;
    }
}
*/

void preter_final_list(t_cmds *cmds_list)
{
    int i;

    while(cmds_list)
    {
        i = 0;
        printf("type = %d\n", cmds_list->type);
        printf("input = %d\n", cmds_list->in_redire);
        printf("output = %d\n", cmds_list->out_redire);
        if(cmds_list->exec_cmd)
        {
            printf("Cmd Type = %d\n", cmds_list->exec_cmd->type);
            printf("CmdPath = %s\n", cmds_list->exec_cmd->path);
            while(cmds_list->exec_cmd->cmd && cmds_list->exec_cmd->cmd[i])
                printf("\'%s\' ", cmds_list->exec_cmd->cmd[i++]);
        }
        printf("\n--------------------------\n");
        cmds_list = cmds_list->next;
    }
}

void	print_array_str(char **s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			printf("%s\n", s[i]);
			i++;
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	t_lexer		*lexer;
	t_cmds		*cmds_list;
	t_token		*token;
	char		*line;
	int			i;

	data = (t_data *) malloc(sizeof(t_data));
	data->env = NULL;
	data->exit_code = 0;
	init_env(&data->list_env, env);
	data->env = update_env(&data->list_env);
	while (1)
	{
		data->signal = 1;
		signals();
		line = readline(GRN "Minishell $: " RESET);
		signal(SIGINT, signal_hander);
		if (!line)
			exit(0);
		if (ft_strlen(line))
			add_history(line);
		lexer = init_lexer(env, line);
		cmds_list = parce_list_shell(lexer);
		 //preter_final_list(cmds_list);
		if (cmds_list)
		{
			execute(cmds_list);
			free_cmds_list(&cmds_list);
		}
		free(lexer->contents);
		free(lexer);
	}
	ft_free_env(data->env);
	free_env(&data->list_env);
}
