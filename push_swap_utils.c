

#include "push_swap.h"


// void	stack_a(t_ps **var, t_ps **head, char *s, int *i)
// {
// 	t_ps	*tmp;

// 	tmp = (t_ps*)malloc(sizeof(t_ps));

// 	tmp->number = atoi(s);

// 	if (*i == 1)
// 	{
// 		(*i)++;
// 		*head = tmp;
// 	}

// 	tmp->next = NULL;
// 	ft_lstadd_back(var, tmp);
// }


// void	ft_lstadd_back(t_ps **lst, t_ps *new)
// {
// 	t_ps	*root;

// 	root = *lst;
// 	if (!(*lst))
// 		*lst = new;
// 	else
// 	{
// 		while (root->next != NULL)
// 			root = root->next;
// 		root->next = new;
// 		new->previous = root;
// 	}
// }

void	push(t_ps **var, t_ps **head, int i)
{
	t_ps	*tmp;

	tmp = (t_ps*)malloc(sizeof(t_ps));
	tmp->number = i;

	tmp->previous = NULL;
	tmp->next = NULL;

	//*head = tmp;
	ft_lstadd_front(var, head, tmp);
}