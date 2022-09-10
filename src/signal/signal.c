#include "../../include/minishell.h"

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