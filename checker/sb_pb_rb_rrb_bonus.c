/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_pb_rb_rrb_opt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:51:52 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/19 15:51:54 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pb_bonus(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b)
{
	t_ps	*lst_a;

	lst_a = *var_a;
	if (!(*var_a))
		return ;
	*head_a = lst_a->next;
	lst_a->next = NULL;
	lst_a->previous = NULL;
	ft_lstadd(var_b, head_b, lst_a);
	*var_a = *head_a;
}

void	sb_bonus(t_ps **var, t_ps	**head)
{
	t_ps	*lst;
	int		count;

	count = 0;
	lst = *var;
	if (!(*var))
		return ;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	if (count == 1)
	{
		*var = *head;
		return ;
	}
	lst = *head;
	switching_sb_sa(lst);
}

void	rb_bonus(t_ps **var_b, t_ps **head_b)
{
	t_ps	*lst;
	int		count;

	lst = *var_b;
	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	if (count == 1)
	{
		*var_b = *head_b;
		return ;
	}
	lst = *head_b;
	reversing_a_b(lst);
	lst = *head_b;
}

void	rrb_bonus(t_ps **var_b, t_ps **head_b)
{
	t_ps	*lst;
	int		a;
	int		b;

	lst = *var_b;
	a = 0;
	b = 0;
	if (!(*var_b))
		return ;
	while (lst->next)
		lst = lst->next;
	while (lst->previous)
	{
		a = lst->number;
		lst = lst->previous;
		b = lst->number;
		lst->number = a;
		lst = lst->next;
		lst->number = b;
		lst = lst->previous;
	}
	lst = *head_b;
}
