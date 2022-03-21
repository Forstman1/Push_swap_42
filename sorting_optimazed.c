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

static void	postivecase(t_ps	**var_b)
{
	int		tmp;
	t_ps	*lst_b;

	lst_b = *var_b;
	if (lst_b->bestmovea == lst_b->bestmoveb)
		lst_b->score = lst_b->bestmovea;
	else
	{
		if (lst_b->bestmovea > lst_b->bestmoveb)
		{
			tmp = lst_b->bestmovea - lst_b->bestmoveb;
			lst_b->score = tmp + lst_b->bestmoveb;
		}
		else
		{
			tmp = lst_b->bestmoveb - lst_b->bestmovea;
			lst_b->score = tmp + lst_b->bestmovea;
		}
	}
}

static void	negativecase(t_ps	**var_b)
{
	int		tmp;
	t_ps	*lst_b;

	lst_b = *var_b;
	if (lst_b->bestmoveb >= 0)
		lst_b->score = (lst_b->bestmovea * -1) + lst_b->bestmoveb;
	else
	{
		if (lst_b->bestmovea == lst_b->bestmoveb)
			lst_b->score = lst_b->bestmovea * -1;
		else
		{
			if (lst_b->bestmovea > lst_b->bestmoveb)
			{
				tmp = (lst_b->bestmoveb * -1) - (lst_b->bestmovea * -1);
				lst_b->score = tmp + (lst_b->bestmovea * -1);
			}
			else
			{
				tmp = (lst_b->bestmovea * -1) - (lst_b->bestmoveb * -1);
				lst_b->score = tmp + (lst_b->bestmoveb * -1);
			}
		}
	}
}

void	bestscore(t_ps **var_b, t_ps **head_b)
{
	t_ps	*lst_b;

	lst_b = *var_b;
	while (lst_b)
	{
		if (lst_b->bestmovea >= 0)
		{
			if (lst_b->bestmoveb >= 0)
			{
				postivecase(&lst_b);
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
			negativecase(&lst_b);
			lst_b = lst_b->next;
		}
	}
}

void	pushtoaoptimazed(t_stack *stacks)
{
	t_ps	*lst_b;
	int		i;

	lst_b = stacks->head_b;
	i = smallistscore(&lst_b);
	lst_b = stacks->head_b;
	while (lst_b)
	{
		if (lst_b->score == i)
			break ;
		lst_b = lst_b->next;
	}
	reset2(stacks);
	optimazed_rules(lst_b, stacks);
	reset2(stacks);
	rulesfor_a(lst_b, stacks);
	reset2(stacks);
	rulesfor_b(lst_b, stacks);
	reset2(stacks);
}

void	stack_sorting(t_stack *stacks, int j)
{
	t_ps	*lst_a;
	t_ps	*lst_b;

	lst_a = stacks->var_a;
	lst_b = stacks->var_b;
	while (lst_b)
	{
		bestmovea(&lst_a, &lst_b, stacks);
		bestmoveinb(&lst_b, &stacks->head_b);
		bestscore(&lst_b, &stacks->head_b);
		lst_b = stacks->head_b;
		lst_a = stacks->var_a;
		pushtoaoptimazed(stacks);
		pa(&lst_a, &stacks->head_a, &lst_b, &stacks->head_b);
		stacks->var_a = stacks->head_a;
		lst_a = stacks->var_a;
		lst_b = stacks->head_b;
	}
}
