#include "../../include/minishell.h"

//handal signal in program  
void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", 1);
        ft_putstr_fd(GRN "Minishell $: " RESET, 1);
		//display_prompt_msg();
		signal(SIGINT, signal_handler);
        data->exit_code = 0;
	}
}

//handel signal in rining procec


void	proc_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		signal(SIGINT, proc_signal_handler);
	}
}

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

void	sigint_handler_nonl(int sig)
{
	// rl_on_new_line();
	// rl_replace_line("", 0);
	// rl_redisplay();
	(void) sig;
}

void	sigint_handler(int sig)
{
	printf("\n");
	// rl_on_new_line();
	// rl_replace_line("", 0);
	// rl_redisplay();
	(void) sig;
}

void	signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}