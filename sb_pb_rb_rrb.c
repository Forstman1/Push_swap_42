/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_pb_rb_rrb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:49:21 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/19 15:49:23 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b)
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
	printf("pb\n");
}

void	switching_sb_sa(t_ps	*lst)
{
	int	a;
	int	lic_a;
	int	b;
	int	lic_b;

	a = 0;
	lic_a = 0;
	b = 0;
	lic_b = 0;
	a = lst->number;
	lic_a = lst->lic;
	lst = lst->next;
	b = lst->number;
	lic_b = lst->lic;
	lst->number = a;
	lst->lic = lic_a;
	lst = lst->previous;
	lst->number = b;
	lst->lic = lic_b;
}

void	sb(t_ps **var, t_ps	**head)
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
	printf("sb\n");
}

void	rb(t_ps **var_b, t_ps **head_b)
{
	t_ps	*lst;
	int		count;

	lst = *var_b;
	count = 0;
	if (!(*var_b))
		return ;
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
	printf("rb\n");
}

void	rrb(t_ps **var_b, t_ps **head_b)
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
	printf("rrb\n");
}
