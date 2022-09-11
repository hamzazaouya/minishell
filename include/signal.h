#include "minishell.h"

//void	signal_handler(int signo);

//void	proc_signal_handler(int signo);

void	signals(void);
void	sigquit_handler_in_process(int sig);
void	sigint_handler_in_process(int sig);
void	sigint_handler_2(int sig);
//void	sigint_handler_nonl(int sig);
//void	signals_handler(void);
// void	signals_handler_child(void);

//void		signal_handler_ctrl_c(int signal);