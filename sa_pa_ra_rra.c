

#include "push_swap.h"



void	pa(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b)
{
	t_ps *lst_b;

	lst_b = *var_b;
	if (!(*var_b))
		return ;
	*head_b = lst_b->next;

	*var_b = *head_b;
	lst_b->next = NULL;
	lst_b->previous = NULL;
	ft_lstadd_front(var_a, head_a, lst_b);
}


void	sa(t_ps **var, t_ps	**head)
{
	t_ps *lst;
	int a1;
	int a2;
	int count;

	a1 = 0;
	a2 = 0;
	count = 0;
	lst = *var;
	if (!(*var))
		return ;
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
}

void	ra(t_ps **var_a, t_ps **head_a)
{
	t_ps	*lst;
	int a;
	int lic_a;
	int lic_b;
	int b;

	lst = *var_a;
	a = 0;
	b = 0;
	if (!(*var_a))
		return ;
	while (lst->next)
	{
		a = lst->number;
		lic_a = lst->lic;
		lst = lst->next;
		b = lst->number;
		lic_b = lst->lic;
		lst->lic = lic_a;
		lst->number = a;
		lst = lst->previous;
		lst->number = b;
		lst->lic = lic_b;
		lst = lst->next;
	}
	*var_a = *head_a;
}

void	rra(t_ps **var_a, t_ps **head_a)
{
	t_ps	*lst;
	int a;
	int lic_a;
	int b;
	int lic_b;

	lst = *var_a;
	a = 0;
	b = 0;
	lic_a = 0;
	lic_b = 0;
	if (!(*var_a))
		return ;
	while (lst->next)
		lst = lst->next;
	
	while (lst->previous)
	{
		//sleep(1);
		a = lst->number;
		lic_a = lst->lic;
		//printf("%d\n", lst->number);
		lst = lst->previous;
		//printf("%d\n", lst->number);
		b = lst->number;
		lic_b = lst->lic;
		lst->lic = lic_a;
		lst->number = a;
		lst = lst->next;
		lst->number = b;
		lst->lic = lic_b;
		lst = lst->previous;
	}
	*var_a = *head_a;
}