/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:57:56 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/18 16:57:57 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd(t_ps **lst, t_ps **head, t_ps *new)
{
	if (!(*lst))
	{
		*lst = new;
		*head = *lst;
		(*lst)->previous = NULL;
	}
	else
	{
		new->next = *lst;
		(*lst)->previous = new;
		*lst = new;
		*head = *lst;
	}
}

void	reset2(t_stack	*stacks)
{
	stacks->var_a = stacks->head_a;
	stacks->var_b = stacks->head_b;
}

void	reset(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b)
{
	*var_a = *head_a;
	*var_b = *head_b;
}

void	bestscore_for_a(t_stack *stacks)
{
	t_ps	*lst_a;

	lst_a = stacks->var_a;
	bestmove_for_a(&stacks->var_a, &stacks->head_a);
	while (lst_a)
	{
		if (lst_a->lic == 0)
		{
			if (lst_a->bestmovea >= 0)
				lst_a->score = lst_a->bestmovea;
			else
				lst_a->score = lst_a->bestmovea * -1;
		}
		lst_a = lst_a->next;
	}
}

void	r_reversing_a(t_ps	*lst)
{
	int		a;
	int		lic_a;
	int		b;
	int		lic_b;

	while (lst->previous)
	{
		a = lst->number;
		lic_a = lst->lic;
		lst = lst->previous;
		b = lst->number;
		lic_b = lst->lic;
		lst->lic = lic_a;
		lst->number = a;
		lst = lst->next;
		lst->number = b;
		lst->lic = lic_b;
		lst = lst->previous;
	}
}
