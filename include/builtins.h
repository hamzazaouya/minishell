/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:53:52 by labenall          #+#    #+#             */
/*   Updated: 2022/09/11 18:53:55 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# define BUFFER_SIZE 100

# include "struct.h"

void	my_env(t_env **env);
void	my_echo(char **src);
int		my_pwd(void);
int		my_cd(char **str_array, t_env **env);
int		my_export(char **arg, t_env **env);
void	my_unset(char **arg, t_env **env);
int		my_exit(char **arg, t_env **env, int k);

#endif
