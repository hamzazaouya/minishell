/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:19:24 by labenall          #+#    #+#             */
/*   Updated: 2022/09/12 23:19:32 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "lexer.h"
# include "parce.h"
# include "env.h"
# include "builtins.h"
# include "aid_funcs.h"
# include "execution.h"
# include "signal.h"
# include <term.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <errno.h>
# include <string.h>
# include "libft/libft.h"
# define GRN   "\x1B[32m"
# define RESET "\x1B[0m"

t_data	*data;

char	*ft_collect(char *s1, char *s2);
void	preter_first_list(t_cmd *cmd_list);
void	preter_final_list(t_cmds *cmds_list);

#endif
