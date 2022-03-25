/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_pa_ra_rra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:37:28 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/18 00:37:30 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b)
{
	t_ps	*lst_b;

	lst_b = *var_b;
	if (!(*var_b))
		return ;
	*head_b = lst_b->next;
	lst_b->next = NULL;
	lst_b->previous = NULL;
	ft_lstadd(var_a, head_a, lst_b);
	*var_b = *head_b;
	write(1, "pa\n", 3);
}

void	sa(t_ps **var, t_ps	**head)
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
	write(1, "sa\n", 3);
}

void	reversing_a_b(t_ps	*lst)
{
	int	a;
	int	lic_a;
	int	lic_b;
	int	b;

	while (lst->next)
	{
		a = lst->number;
		lic_a = lst->lic;
		lst = lst->next;
		b = lst->number;
		lic_b = lst->lic;
		lst->lic = lic_a;
		lst->number = a;
		lst = lst->previous;
		lst->number = b;
		lst->lic = lic_b;
		lst = lst->next;
	}
}

void	ra(t_ps **var_a, t_ps **head_a)
{
	t_ps	*lst;

	lst = *var_a;
	if (!(*var_a))
		return ;
	reversing_a_b(lst);
	*var_a = *head_a;
	write(1, "ra\n", 3);
}

void	rra(t_ps **var_a, t_ps **head_a)
{
	t_ps	*lst;

	lst = *var_a;
	if (!(*var_a))
		return ;
	while (lst->next)
		lst = lst->next;
	r_reversing_a(lst);
	write(1, "rra\n", 4);
}
