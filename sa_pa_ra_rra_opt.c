/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_pa_ra_rra_opt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 05:51:54 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/19 05:51:56 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_opt(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b)
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
}

void	sa_opt(t_ps **var, t_ps	**head)
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

void	ra_opt(t_ps **var_a, t_ps **head_a)
{
	t_ps	*lst;

	lst = *var_a;
	if (!(*var_a))
		return ;
	reversing_a_b(lst);
	*var_a = *head_a;
}

void	rra_opt(t_ps **var_a, t_ps **head_a)
{
	t_ps	*lst;

	lst = *var_a;
	if (!(*var_a))
		return ;
	while (lst->next)
		lst = lst->next;
	r_reversing_a(lst);
}

void	error_duplicate(char	**splited, int *array)
{
	free_parsing(splited);
	free(array);
	error();
}
