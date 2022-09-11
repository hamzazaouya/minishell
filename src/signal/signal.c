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

void	sigint_handler_2(int sig)
{
	
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	(void) sig;
}

void	sigint_handler(int sig)
{
	if (data->signal)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	(void) sig;
}


void	signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}


// void signals_child()
// {
// 	signal(SIGINT, SIGKILL);
// 	signal(SIGQUIT, SIGKILL);
// }