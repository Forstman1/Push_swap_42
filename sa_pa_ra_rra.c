

#include "push_swap.h"



void	pa(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b)
{
	t_ps *lst_b;

	lst_b = *var_b;
	if (!(*var_b))
		return ;
	*head_b = lst_b->next;

	lst_b->next = NULL;
	ft_lstadd_front(var_a, head_a, lst_b);
}


void	sa(t_ps **var, t_ps	**head)
{
	t_ps *lst;
	int a1;
	int a2;

	a1 = 0;
	a2 = 0;
	lst = *var;
	if (!(*var))
		return ;
	a1 = lst->number;
	lst = lst->next;
	a2 = lst->number;
	lst->number = a1;
	lst = lst->previous;
	lst->number = a2;
	*var = *head;
}

void	ra(t_ps **var_a, t_ps **head_a)
{
	t_ps	*lst;
	int a;
	int b;

	lst = *var_a;
	a = 0;
	b = 0;
	if (!(*var_a))
		return ;
	while (lst)
	{
		a = lst->number;
		lst = lst->next;
		b = lst->number;
		lst->number = a;
		lst = lst->previous;
		lst->number = b;
		lst = lst->next;
	}
	lst = *head_a;
}

void	rra(t_ps **var_a, t_ps **head_a)
{
	t_ps	*lst;
	int a;
	int b;

	lst = *var_a;
	a = 0;
	b = 0;
	if (!(*var_a))
		return ;
	while (lst->next)
	{
		lst = lst->next;
	}
	while (lst->previous)
	{
		a = lst->number;
		lst = lst->previous;
		b = lst->number;
		lst->number = a;
		lst = lst->next;
		lst->number = b;
		lst = lst->previous;
	}
	lst = *head_a;
}