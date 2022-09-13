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

#include "../include/minishell.h"
#include "../include/struct.h"

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

void	free_lexer(t_lexer **lexer)
{
	free((*lexer)->contents);
	free(*lexer);
}

void	free_all_env(void)
{
	ft_free_env(data->env);
	free_env(&data->list_env);
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
		if (cmds_list)
		{
			execute(cmds_list);
			free_cmds_list(&cmds_list);
		}
		free_lexer(&lexer);
	}
	free_all_env();
}
