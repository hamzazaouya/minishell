#include "../include/minishell.h"
#include "../include/lexer.h"
#include "../include/parce.h"

int main(int argc, char ** argv, char **env)
{
    t_lexer* lexer;
    t_cmd   *cmd_list;
    t_token *token;
    char *line;
    int i;
    exit_code = 0;

    while(1)
    {
        line = readline(GRN "Minishell $: " RESET);
        add_history(line);
        lexer = init_lexer(env, line);
        cmd_list = parce_list_shell(lexer);

        // while(token_list)
        // {
        //     printf("-->>value = %s, type = %d, \n", token_list->value, token_list->type);
        //     token_list = token_list->next;
        // }
        while(cmd_list)
        {
            i = 0;
            //printf("%p %s\n", cmd_list->cmd, cmd_list->cmd[i]);
            while(cmd_list->cmd && cmd_list->cmd[i])
                printf("\"%s\", \n", cmd_list->cmd[i++]);
            while(cmd_list->redire_list)
            {
                printf("type = %d, value = %s\n",cmd_list->redire_list->type, cmd_list->redire_list->value);
                cmd_list->redire_list = cmd_list->redire_list->next;
            }
            printf("-------------\n");
            cmd_list = cmd_list->next;
        //}
        // while((token = lexer_get_next_token(lexer)) && token->type != TOKEN_END)
        // {
        //     printf("Token(%d, %s)\n", token->type, token->value);
        //     free(token->value);
        //     free(token);
        }
        free(line);
        parce_free_cmd_shell(cmd_list);
        exit_code = 0;
    }
}