/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:35:03 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/08 14:35:04 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortingprocess(int t, int i, t_ps *lst, t_ps **head_a)
{
	if (t <= (i / 2))
	{
		lst = *head_a;
		while (t > 0)
		{
			ra(&lst, head_a);
			t--;
		}
		return ;
	}
	else
	{
		lst = *head_a;
		lst->previous = NULL;
		while (i > t)
		{
			rra(&lst, head_a);
			i--;
		}
		return ;
	}
}

void	sortingcount(t_ps **var_a, t_ps **head_a, int j)
{
	int		i;
	int		t;
	t_ps	*lst;

	i = 0;
	t = 0;
	lst = *var_a;
	i = lenghtoflist(lst);
	lst = *var_a;
	while (lst)
	{
		if (lst->number == j)
		{
			sortingprocess(t, i, *var_a, head_a);
			return ;
		}
		else
			lst = lst->next;
		t++;
	}
}

int	biggestnumber(t_ps **var_a, int j, int i_value)
{
	int		t;
	int		lenght;
	t_ps	*lst_a;

	t = 0;
	lst_a = *var_a;
	lenght = lenghtoflist(lst_a);
	lst_a = *var_a;
	if (lst_a->number > i_value)
		return (0);
	while (lst_a)
	{
		if (lst_a->number == j)
		{
			if (t < (lenght / 2))
				return (t);
			else
				return ((lenght - t + 1) * -1);
		}
		t++;
		lst_a = lst_a->next;
	}
	return (0);
}

static int	checkingnumbers(t_ps **var_a, int i_value, int lenght, int j)
{
	int		i;
	t_ps	*lst_a;

	i = 0;
	lst_a = *var_a;
	while (lst_a)
	{
		i++;
		if (lst_a->number < i_value)
		{
			lst_a = lst_a->next;
			if (!lst_a)
				return (biggestnumber(var_a, j, i_value));
			if (lst_a->number > i_value)
			{
				if (i <= (lenght / 2))
					return (i);
				else
					return ((lenght - i + 1) * -1);
			}
		}
		else
			lst_a = lst_a->next;
	}
	return (0);
}

void	bestmovea(t_ps	**var_a, t_ps	**var_b, t_stack *stacks)
{
	t_ps	*lst_a;
	t_ps	*lst_b;
	int		lenght;
	int		i_value;
	int		j;

	lst_a = *var_a;
	lst_b = *var_b;
	lenght = 0;
	i_value = 0;
	j = smallistnumber(&lst_a);
	lst_a = *var_a;
	while (lst_a)
	{
		lenght++;
		lst_a = lst_a->next;
	}
	lst_a = stacks->head_a;
	while (lst_b)
	{
		lst_a = stacks->head_a;
		i_value = lst_b->number;
		lst_b->bestmovea = checkingnumbers(&lst_a, i_value, lenght, j);
		lst_b = lst_b->next;
	}
}
