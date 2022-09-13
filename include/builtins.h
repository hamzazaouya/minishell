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

void		my_env(t_env **env);
void		my_echo(char **src);
int			my_pwd(void);
int			my_cd(char **str_array, t_env **env);
int			my_export(char **arg, t_env **env);
void		my_unset(char **arg, t_env **env);
int			my_exit(char **arg, t_env **env, int k);
void		ft_update_pwd(t_env **env, char *old_pwd);
void		ft_do_cd(char **str_array, t_env **env);
t_env		*ft_ch_value(t_env *ht, char *key, char *value);
int			size_of_list(t_env *env);
char		*get_type_pro(char *s, int *k);
int			type_exist(t_env **env, char *type);
void		modifier_env(t_env **env, char *type, char *content);
void		concatiner(t_env **env, char *type, char *content);
void		ajouter_env(t_env **env, char *type, char *content);
void		declare_print(t_env *env);
int			cheak_arg(char **arg);
char		*get_content_pro(char *arg);
int			help_type_pro(char *s, int *k, size_t *i);

#endif
