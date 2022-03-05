

#include "push_swap.h"


void	push(t_ps **var, t_ps **head, t_ps **tail, int i)
{
	t_ps	*tmp;

	
	tmp = (t_ps*)malloc(sizeof(t_ps));
	tmp->number = i;
	if (!(*var))
		*tail = tmp;
	tmp->previous = NULL;
	tmp->next = NULL;
	tmp->index = 1;
	//*head = tmp;
	ft_lstadd_front(var, head, tmp);
}