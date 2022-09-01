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