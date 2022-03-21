/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:00:00 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/17 18:00:03 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_ps **var, t_ps **head, int i)
{
	t_ps	*tmp;

	tmp = (t_ps *)malloc(sizeof(t_ps));
	tmp->number = i;
	tmp->previous = NULL;
	tmp->next = NULL;
	tmp->index = 1;
	ft_lstadd(var, head, tmp);
}

void	lis(t_ps **var_a, t_ps **head)
{
	int		j;
	int		j_value;
	t_ps	*var;
	int		t;

	j = 0;
	var = *var_a;
	while (var->next)
	{
		var = var->next;
		j_value = var->number;
		j = var->index;
		var->index = checkprevious(*var_a, *head, j_value, &t);
		if (var->index >= j)
			var->subsequence = t;
	}
}

int	checkprevious(t_ps	*var_a, t_ps	*head_a, int j_value, int *t)
{
	int	i_value;
	int	returned;
	int	j;

	*t = 0;
	returned = 0;
	j = var_a->index;
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
	return (returned);
}

void	reset_to_smallist_number(t_ps	**var_a, t_ps	**head_a, int j)
{
	t_ps	*lst_a;

	lst_a = *head_a;
	while (lst_a)
	{
		sortingcount(&lst_a, head_a, j);
		lst_a = lst_a->next;
	}
}

int	lenghtoflist(t_ps	*lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
