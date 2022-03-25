/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushtostackb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:15:27 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/12 14:15:29 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pushingtob_utils(t_ps	*lst, t_stack *stacks)
{
	while (lst->bestmovea > 0)
	{
		ra(&stacks->var_a, &stacks->head_a);
		lst->bestmovea--;
	}
	stacks->var_a->previous = NULL;
	while (lst->bestmovea < 0)
	{
		rra(&stacks->var_a, &stacks->head_a);
		lst->bestmovea++;
	}
	pb(&stacks->var_a, &stacks->head_a, &stacks->var_b, \
		&stacks->head_b);
}

static int	pushingtob(t_stack *stacks, int i)
{
	t_ps	*lst;

	lst = stacks->var_a;
	while (lst)
	{
		if (lst->lic == 0)
		{
			if (lst->score == i)
			{
				pushingtob_utils(lst, stacks);
				return (1);
			}
		}
		lst = lst->next;
	}
	return (0);
}

static void	subsequence(t_ps	*lst_a)
{
	int	caase;

	caase = 0;
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
}

void	lic_process(t_stack *stacks)
{
	int		i;
	t_ps	*lst_a;

	i = 0;
	lst_a = stacks->head_a;
	while (lst_a)
	{
		if (i < lst_a->index)
			i = lst_a->index;
		lst_a = lst_a->next;
	}
	lst_a = stacks->head_a;
	while (lst_a->next)
		lst_a = lst_a->next;
	while (lst_a->previous)
	{
		if (i == lst_a->index)
		{
			subsequence(lst_a);
			break ;
		}
		lst_a = lst_a->previous;
	}
}

void	pushingtostackb(t_stack *stacks)
{
	t_ps	*lst_a;
	int		i;
	int		j;

	lst_a = stacks->head_a;
	lic_process(stacks);
	i = 0;
	j = 0;
	while (lst_a)
	{
		bestscore_for_a(stacks);
		lst_a = stacks->head_a;
		i = smallistscore(&stacks->var_a);
		lst_a = stacks->head_a;
		j = pushingtob(stacks, i);
		if (j == 0)
			break ;
		lst_a = stacks->head_a;
	}
	lst_a = stacks->head_a;
}
