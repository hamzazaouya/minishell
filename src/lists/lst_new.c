#include "../../includes/minishell.h"

void	init_list(t_cmds *lst)
{
	lst->command = NULL;
	lst->in_f = 0;
	lst->out_f = 1;
	lst->is_herdog = 0;
	lst->next = NULL;
}

t_cmds	*ft_lstnew(void)
{
	t_cmds	*lst;

	lst = 	(t_cmds *) ft_calloc(1, sizeof(t_cmds));
	if (!lst)
		return (NULL);
	init_list(lst);
	return (lst);
}

t_cmds	*ft_lstlast(t_cmds *lst)
{
	t_cmds	*last;

	if (lst == NULL)
		return (lst);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_lstadd_back(t_cmds **lst, t_cmds *new)
{
	t_cmds	*last;

	if (lst == NULL)
		return ;
	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}