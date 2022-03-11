/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_optimazed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:03:54 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/10 20:03:57 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	bestscore(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b)
{
	t_ps	*lst_a;
	t_ps	*lst_b;

	lst_a = *var_a;
	lst_b = *var_b;

	while (lst_b)
	{
		if (lst_b->bestmovea > 0)
		{
			if (lst_b->bestmoveb > 0)
			{
				lst_b->score = (lst_b->bestmovea + lst_b->bestmoveb) / 2;
				lst_b = lst_b->next;
			}
			else
			{
				lst_b->score = lst_b->bestmovea + (lst_b->bestmoveb * -1);
				lst_b = lst_b->next;
			}
		}
		else
		{
			if (lst_b->bestmoveb > 0)
			{
				lst_b->score = (lst_b->bestmovea * -1) + lst_b->bestmoveb;
				lst_b = lst_b->next;
			}
			else
			{
				lst_b->score = ((lst_b->bestmovea * -1) + (lst_b->bestmoveb * -1)) / 2;
				lst_b = lst_b->next;
			}
		}
	}
}

int	pushtoaoptimazed(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b, int j)
{
	t_ps	*lst_a;
	t_ps	*lst_b;
	int i;
	int t;

	lst_a = *var_a;
	lst_b = *var_b;
	t = 0;
	lst_a = *var_a;
	lst_b = *var_b;
	i = lst_b->score;
	while (lst_b)
	{
		if (lst_b->score < i)
			i = lst_b->score;
		lst_b = lst_b->next;
	}
	lst_b = *head_b;
	while (lst_b)
	{
		if (lst_b->score == i)
			break ;
		lst_b = lst_b->next;
	}

	reset(var_a, head_a, var_b, head_b);
	while (lst_b->bestmovea > 0 && lst_b->bestmoveb > 0)
	{
		rr(var_a, head_a, var_b, head_b);
		lst_b->bestmovea--;
		lst_b->bestmoveb--;
	}	
	reset(var_a, head_a, var_b, head_b);
	(*var_b)->previous = NULL;
	(*var_a)->previous = NULL;
	if (lst_b->bestmovea < 0 && lst_b->bestmoveb < 0)
	{
		while (lst_b->bestmovea < 0 && lst_b->bestmoveb < 0)
		{
			rrr(var_a, head_a, var_b, head_b);
			t = 1;
			lst_b->bestmovea++;
			lst_b->bestmoveb++;
		}
	}
	reset(var_a, head_a, var_b, head_b);
	while (lst_b->bestmovea < 0)
	{
		rra(var_a, head_a);
		lst_b->bestmovea += 1;
		t = 1;
	}
	reset(var_a, head_a, var_b, head_b);
	while (lst_b->bestmovea > 0)
	{
		ra(var_a, head_a);
		lst_b->bestmovea -= 1;
	}
	(*var_b)->previous = NULL;
	while (lst_b->bestmoveb < 0)
	{
		rrb(var_b, head_b);
		lst_b->bestmoveb += 1;
	}
	reset(var_a, head_a, var_b, head_b);
	while (lst_b->bestmoveb > 0)
	{
		rb(var_b, head_b);
		lst_b->bestmoveb -= 1;
	}
	return (t);
}


void	stack_sorting(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b, int j)
{
	t_ps	*lst_a;
	t_ps	*lst_b;
	int i;

	lst_a = *var_a;
	lst_b = *var_b;
	i = 0;
	while (lst_b)
	{
		*var_b = *head_b;
		i = pushtoaoptimazed(var_a, head_a , &lst_b, head_b, j);
		reset(var_a, head_a, var_b, head_b);
		pa(&lst_a, head_a, &lst_b, head_b);
		if (i == 1)
			sa(&lst_a, head_a);
		lst_a = *head_a;
		lst_b = *head_b;
		while (lst_a)
		{
			sortingcount(&lst_a, head_a, j);
			lst_a = lst_a->next;
		}
		lst_a = *head_a;
		bestmovea(&lst_a, head_a, &lst_b, head_b);
		bestmoveinb(&lst_b, head_b);
		bestscore(&lst_a, head_a, &lst_b, head_b);
		lst_a = *head_a;
		lst_b = *head_b;
	}
}