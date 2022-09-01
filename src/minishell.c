#include "../include/minishell.h"
#include "../include/lexer.h"
#include "../include/parce.h"



int main(int argc, char ** argv, char **env)
{
    t_lexer*	lexer;
    t_cmds		*cmds_list;
    t_token		*token;
    char		*line;
    int			i;


	data = (t_data *) malloc(sizeof(t_data));
	data->exit_code = 0;
    init_env(&(data->list_env), env);
    //signal(SIGINT, signal_handler);
    //pritnt env
    //my_env(&list_env);
    while(1)
    {
        data->signal = 0;
        line = readline(GRN "Minishell $: " RESET);
        if(!line)
        {
            printf(GRN "\nMinishell $: " RESET);
            printf("exit\n");
            exit(0);
        }
        add_history(line);
        lexer = init_lexer(env, line);
        cmds_list = parce_list_shell(lexer);
        preter(cmds_list);
        // while(token_list)
        // {
        //     printf("-->>value = %s, type = %d, \n", token_list->value, token_list->type);
        //     token_list = token_list->next;
        // }
        // while(cmd_list)
        // {
        //     i = 0;
        //     //printf("%p %s\n", cmd_list->cmd, cmd_list->cmd[i]);
        //     while(cmd_list->cmd && cmd_list->cmd[i])
        //         printf("\"%s\", \n", cmd_list->cmd[i++]);
        //     while(cmd_list->redire_list)
        //     {
        //         printf("type = %d, value = %s\n",cmd_list->redire_list->type, cmd_list->redire_list->value);
        //         cmd_list->redire_list = cmd_list->redire_list->next;
        //     }
        //     printf("-------------\n");
        //     cmd_list = cmd_list->next;
        //}
        // while((token = lexer_get_next_token(lexer)) && token->type != TOKEN_END)
        // {
        //     printf("Token(%d, %s)\n", token->type, token->value);
        //     free(token->value);
        //     free(token);
        //}
        free(line);
        //parce_free_cmd_shell(cmds_list);
        data->exit_code = 0;
    }
    free(data->list_env);
}