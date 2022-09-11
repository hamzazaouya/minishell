/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:58:06 by labenall          #+#    #+#             */
/*   Updated: 2022/09/11 18:58:09 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

# include "minishell.h"

void	signals(void);
void	sigquit_handler_in_process(int sig);
void	sigint_handler_in_process(int sig);
void	signal_hander(int sig);

#endif
