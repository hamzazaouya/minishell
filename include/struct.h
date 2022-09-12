/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:58:18 by labenall          #+#    #+#             */
/*   Updated: 2022/09/11 18:58:20 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_env
{
	char			*type;
	char			*content;
	struct s_env	*next;
}				t_env;

typedef struct s_lexer
{
	char			c;
	unsigned int	i;
	char			*contents;
	char			**env;
}				t_lexer;

typedef struct token_struct
{
	enum
	{
		TOKEN_INF,
		TOKEN_HERDOC,
		TOKEN_OUTF,
		TOKEN_APPEND,
		TOKEN_WORD,
		TOKEN_PIPE,
		TOKEN_END,
	}	type;
	char	*value;
}			t_token;

typedef struct s_redire
{
	int				fd[2];
	int				type;
	char			*value;
	struct s_redire	*next;
}				t_redire;

typedef struct s_cmd
{
	int				type;
	char			**cmd;
	t_redire		*redire_list;
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_exec_cmd
{
	int		type;
	char	**cmd;
	char	*path;
}				t_exec_cmd;

typedef struct s_cmds
{
	int				type;
	int				in_redire;
	int				out_redire;
	t_exec_cmd		*exec_cmd;
	struct s_cmds	*next;
}				t_cmds;

typedef struct s_data
{
	int		signal;
	int		exit_code;
	char	**env;
	t_env	*list_env;
}		t_data;

#endif
