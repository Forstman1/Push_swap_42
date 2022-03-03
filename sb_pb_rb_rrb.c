


#include "push_swap.h"


void	pb(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b)
{
	t_ps *lst_a;

	lst_a = *var_a;
	if (!(*var_a))
		return ;
	*head_a = lst_a->next;

	*var_a = *head_a;
	lst_a->next = NULL;
	lst_a->previous = NULL;
	ft_lstadd_front(var_b, head_b, lst_a);
}

void	sb(t_ps **var, t_ps	**head)
{
	t_ps *lst;
	int a1;
	int a2;
	int count;

	if (!(*var))
		return ;
	a1 = 0;
	a2 = 0;
	count = 0;
	lst = *var;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	if (count == 1)
	{
		*var = *head;
		return ;
	}
	lst = *head;
	a1 = lst->number;
	lst = lst->next;
	a2 = lst->number;
	lst->number = a1;
	lst = lst->previous;
	lst->number = a2;
	*var = *head;
}

void	rb(t_ps **var_b, t_ps **head_b)
{
	t_ps	*lst;
	int a;
	int b;

	lst = *var_b;
	a = 0;
	b = 0;
	while (lst->next)
	{
		a = lst->number;
		lst = lst->next;
		b = lst->number;
		lst->number = a;
		lst = lst->previous;
		lst->number = b;
		lst = lst->next;
	}
	lst = *head_b;
}

void	rrb(t_ps **var_b, t_ps **head_b)
{
	t_ps	*lst;
	int a;
	int b;

	lst = *var_b;
	a = 0;
	b = 0;
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
	lst = *head_b;
}