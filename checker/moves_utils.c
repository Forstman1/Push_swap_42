/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:55:52 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/19 15:55:54 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	push(t_ps **var, t_ps **head, int i)
{
	t_ps	*tmp;

	tmp = (t_ps *)malloc(sizeof(t_ps));
	tmp->number = i;
	tmp->previous = NULL;
	tmp->next = NULL;
	tmp->index = 1;
	ft_lstadd(var, head, tmp);
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
