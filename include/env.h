/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:55:11 by labenall          #+#    #+#             */
/*   Updated: 2022/09/11 18:55:13 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include <stdlib.h>
# include "minishell.h"
# include "struct.h"

void	init_env(t_env **list_env, char **env);
char	**update_env(t_env **env);
void	ft_free_env(char **holder);
char	*get_content_from_env(t_env *list_env, char *type);
void	free_env(t_env **list_env);
char	*get_content(char *content);
char	*get_type(char *type);
t_env	*ft_listnew_env(char *type, char *content);
void	ft_listadd_back_env(t_env **list_env, t_env *new);
int		ft_strcmp(char *s1, char *s2);
char	*ft_str(char *type, size_t s);
void	print_array_str(char **s);

#endif
