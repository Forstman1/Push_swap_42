

#include "push_swap.h"


void	push(t_ps **var, t_ps **head, int i)
{
	t_ps	*tmp;

	
	tmp = (t_ps*)malloc(sizeof(t_ps));
	tmp->number = i;
	tmp->previous = NULL;
	tmp->next = NULL;
	tmp->index = 1;
	ft_lstadd_front(var, head, tmp);
}


void	lis(t_ps **var_a, t_ps **head)
{
	int j;
	int j_value;
	t_ps	*var;
	int i;
	int t;

	j = 0;
	var = *var_a;
	while (var->next)
	{
		var = var->next;
		j_value = var->number;
		j = var->index;
		var->index = checkprevious(*var_a, *head, j_value, j, &t);
		if (var->index >= j)
			var->subsequence = t;
	}
}

int	checkprevious(t_ps	*var_a, t_ps	*head_a, int j_value, int j, int *t)
{
	int i;
	int i_value;
	int returned;

	i = 0;
	*t = 0;
	returned = 0;
	var_a = head_a;
	i_value = var_a->number;
	while (i_value != j_value)
	{
		if (i_value < j_value)
		{
			if ((var_a->index + 1) >= j)
			{
				returned = var_a->index + 1;
				j = returned;
				*t = var_a->count;
			}
		}
		var_a = var_a->next;
		i_value = var_a->number;
	}
	return returned;
}

int	checkprevious_test(t_ps	*var_a, t_ps	*head_a, t_ps	*head_fake, int j_value, int j, int *t)
{
	int i;
	int i_value;
	int returned;

	i = 0;
	*t = 0;
	returned = 0;
	var_a = head_a;
	i_value = var_a->number;
	while ((i_value != j_value) && (var_a))
	{
		if (i_value < j_value)
		{
			if ((var_a->index + 1) >= j)
			{
				returned = var_a->index + 1;
				j = returned;
				*t = var_a->count;
			}
		}
		var_a = var_a->next;
		i_value = var_a->number;
	}
	return returned;
}


void	lis_test(t_ps	**var_a, t_ps	**head_a, t_ps	**head_fake, t_ps **tails, t_ps **tmp1, t_ps **tmp2)
{
	int j;
	int j_value;
	t_ps	*var;
	t_ps	*lst_a;
	int i;
	int t;
	int caase;

	j = 0;
	caase = 0;
	t = 0;
	var = *head_fake;
	while (var)
	{
		var->count = t + 1;
		t++;
		var = var->next;
	}
	var = *head_a;
	while (var != *head_fake)
	{
		var->count = t + 1;
		t++;
		var = var->next;
	}
	var = *head_fake;
	(*head_fake)->count = 0;
	while (var->next)
	{
		var = var->next;
		j_value = var->number;
		j = var->index;
		var->index = checkprevious(var, *head_fake, j_value, j, &t);
		if (var->index >= j)
			var->subsequence = t;	
	}

	var = *head_a;

	while (var != *head_fake)
	{
		var = var->next;
		j_value = var->number;
		j = var->index;
		var->index = checkprevious_test(var, *head_a, *head_fake, j_value, j, &t);
		if (var->index >= j)
			var->subsequence = t;	
	}

	i = 0;
	lst_a = *head_fake;
	lst_a->subsequence = 0;
	while (lst_a->next)
	{
		if (i < lst_a->index)
			i = lst_a->index;
		lst_a = lst_a->next;
	}
	
	lst_a = *head_a;
	
	while (lst_a != (*head_fake)->next)
	{
		if (i < lst_a->index)
			i = lst_a->index;
		lst_a = lst_a->next;
	}
	j = lst_a->count;


	while (lst_a->previous)
	{
		if (i == lst_a->index)
		{
			lst_a->lic = 1;
			caase = lst_a->subsequence;
			while (lst_a)
			{
				if (caase == lst_a->count)
				{
					lst_a->lic = 1;
					caase = lst_a->subsequence;
				}
				lst_a = lst_a->previous;
			}
			break ;
		}
		lst_a = lst_a->previous;
	}
	lst_a = *head_fake;
	while (lst_a->next)
		lst_a = lst_a->next;
	while (lst_a != (*head_fake)->previous)
	{
		if (i == lst_a->index)
		{
			lst_a->lic = 1;
			caase = lst_a->subsequence;
			while (lst_a)
			{
				if (caase == lst_a->count)
				{
					lst_a->lic = 1;
					caase = lst_a->subsequence;
				}
				lst_a = lst_a->previous;
			}
			break ;
		}
		lst_a = lst_a->previous;
	}
	(*head_fake)->lic = 1;
	// printf("%d--|%d\n", lst_a->number, lst_a->count);
	// lst_a = *head_a;
	// while (lst_a)
	// {
	// 	printf("%d-|%d\n", lst_a->number, lst_a->lic);
	// 	lst_a = lst_a->next;
	// }
	lst_a = *head_a;
}