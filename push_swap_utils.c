

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
		if (var->index > j)
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

void	bestscore_for_a(t_ps **var_a, t_ps **head_a)
{
	t_ps	*var;
	int		i;

	i = 0;
	var = *var_a;
	while (var)
	{
		i++;
		var = var->next;
	}
	var = *var_a;
	while (var)
	{
		if (var->lic == 0)
			var->bestmovea = checkmoves(var, var_a, head_a, i);
		var = var->next;
	}
	var = *var_a;
}

