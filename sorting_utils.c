/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:42:18 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/09 15:42:19 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkmoves(t_ps *var, t_ps **var_b, t_ps **head_b, int i)
{
	t_ps	*lst;
	int		j;
	int		t;

	lst = *var_b;
	j = 0;
	t = 0;
	while (lst->number != var->number)
	{
		if (j < (i / 2))
		{
			j++;
			lst = lst->next;
		}
		else
		{
			j++;
			t = i - j;
			t = t * -1;
			lst = lst->next;
		}
	}
	if (t < 0)
		return (t);
	return (j);
}

void	bestmoveinb(t_ps **var_b, t_ps **head_b)
{
	t_ps	*var;
	int		i;

	i = 0;
	var = *var_b;
	while (var)
	{
		i++;
		var = var->next;
	}
	var = *var_b;
	while (var)
	{
		var->bestmoveb = checkmoves(var, var_b, head_b, i);
		var = var->next;
	}
}

void	optimazed_rules(t_ps	*lst_b, t_stack	*stacks)
{
	while (lst_b->bestmovea > 0 && lst_b->bestmoveb > 0)
	{
		rr(&stacks->var_a, &stacks->head_a, &stacks->var_b, &stacks->head_b);
		lst_b->bestmovea--;
		lst_b->bestmoveb--;
	}
	reset2(stacks);
	stacks->var_b->previous = NULL;
	stacks->var_a->previous = NULL;
	while (lst_b->bestmovea < -1 && lst_b->bestmoveb < 0)
	{
		rrr(&stacks->var_a, &stacks->head_a, &stacks->var_b, &stacks->head_b);
		lst_b->bestmovea++;
		lst_b->bestmoveb++;
	}
	reset2(stacks);
}

void	rulesfor_a(t_ps	*lst_b, t_stack	*stacks)
{
	stacks->var_a->previous = NULL;
	while (lst_b->bestmovea < -1)
	{
		rra(&stacks->var_a, &stacks->head_a);
		lst_b->bestmovea += 1;
	}
	reset2(stacks);
	while (lst_b->bestmovea > 0)
	{
		ra(&stacks->var_a, &stacks->head_a);
		lst_b->bestmovea -= 1;
	}
}

void	rulesfor_b(t_ps	*lst_b, t_stack	*stacks)
{
	stacks->var_b->previous = NULL;
	while (lst_b->bestmoveb < 0)
	{
		rrb(&stacks->var_b, &stacks->head_b);
		lst_b->bestmoveb += 1;
	}
	reset2(stacks);
	while (lst_b->bestmoveb > 0)
	{
		rb(&stacks->var_b, &stacks->head_b);
		lst_b->bestmoveb -= 1;
	}
	reset2(stacks);
}
