

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
		if (var->index > j)
		{
			var->subsequence = t;
		}
	}
}

void	pushingtostackb(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b)
{
	int caase;
	t_ps	*lst_a;
	t_ps	*lst_b;
	int i;
	int j;
	int t;

	i = 0;
	t = 0;
	caase = 0;
	lst_a = *var_a;
	lst_b = *var_b;
	while (lst_a->next)
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
	lst_a = *var_a;
	i = 0;
	while (lst_a)
	{
		if (i < (j / 2))
		{
			if (lst_a->lic == 0)
			{
				reset(&lst_a, head_a, var_b, head_b);
				while (i > 0)
				{
					ra(&lst_a, head_a);
					i--;
				}
				pb(&lst_a, head_a, var_b, head_b);
				reset(&lst_a, head_a, var_b, head_b);
				i = 0;
			}
			else
			{
				lst_a = lst_a->next;
				i++;
			}
		}
		else
			if (lst_a->lic == 0)
			{
				i = j;
				lst_a->previous = NULL;
				reset(&lst_a, head_a, var_b, head_b);
				while (i > (j / 2))
				{
					rra(&lst_a, head_a);
					i--;
				}
				pb(&lst_a, head_a, var_b, head_b);
				reset(&lst_a, head_a, var_b, head_b);
				i = 0;
			}
			else
			{
				lst_a = lst_a->next;
				i++;
			}
	}
}