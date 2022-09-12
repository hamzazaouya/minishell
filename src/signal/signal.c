/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:50:16 by labenall          #+#    #+#             */
/*   Updated: 2022/09/11 18:50:18 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sigint_handler_in_process(int sig)
{
	(void) sig;
	printf("\n");
}

void	sigquit_handler_in_process(int sig)
{
	(void) sig;
	printf("Quit: %d\n", sig);
}

void	sigint_handler(int sig)
{
	if (data->signal)
	{
		printf("\n");
		//rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	(void) sig;
}

void	signal_hander(int sig)
{
	write(1, "\n", 1);
	(void)sig;
}

void	signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}
