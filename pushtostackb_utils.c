/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:10:58 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/15 18:11:00 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallistscore(t_ps **var_a)
{
	t_ps	*lst_a;
	int		i;

	lst_a = *var_a;
	i = 0;
	while (lst_a)
	{
		if (lst_a->lic == 0)
		{
			i = lst_a->score;
			while (lst_a)
			{
				if (lst_a->lic == 0)
					if (lst_a->score < i)
						i = lst_a->score;
				lst_a = lst_a->next;
			}
			return (i);
		}
		lst_a = lst_a->next;
	}
	return (0);
}

void	bestmove_for_a(t_ps **var_a, t_ps **head_a)
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
	*var_a = *head_a;
}

void	twocases(t_stack	*stacks, int i)
{
	int		first;
	t_ps	*lst;
	int		second;

	lst = stacks->var_a;
	if (i == 2)
	{
		first = 0;
		second = 0;
		first = lst->number;
		lst = lst->next;
		second = lst->number;
		if (first > second)
			sa(&stacks->var_a, &stacks->head_a);
	}
	else
		return ;
}

void	error(void)
{
	write(1, "ERROR\n", 6);
	exit(0);
}
