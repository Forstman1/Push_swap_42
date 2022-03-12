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

int	checkmoves(t_ps *var ,t_ps **var_b, t_ps **head_b, int i)
{
	t_ps	*lst;
	int j;
	int t;

	lst = *var_b;
	j = 0;
	t = 0;
	while (lst->number != var->number)
	{
		if (j < (i / 2))
		{
			j++;
			lst = lst->next;
		}
		else
		{
			j++;
			t = i - j;
			t = t * -1;
			lst = lst->next;
		}
	}
	if (t < 0)
		return (t);
	return (j);
}

void	bestmoveinb(t_ps **var_b, t_ps **head_b)
{
	t_ps	*var;
	int		i;

	i = 0;
	var = *var_b;
	while (var)
	{
		i++;
		var = var->next;
	}
	var = *var_b;
	while (var)
	{
		var->bestmoveb = checkmoves(var, var_b, head_b, i);
		var = var->next;
	}
}

void	sortingcount(t_ps	**var_a, t_ps	**head_a, int j)
{
	int i;
	int t;
	t_ps	*lst;

	i = 0;
	t = 0;
	lst = *var_a;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	lst = *var_a;
	while (lst)
	{
		if (t <= (i / 2))
		{
			if (lst->number == j)
			{
				lst = *var_a;
				while (t > 0)
				{
					ra(&lst, head_a);
					t--;
				}
				return ;
			}
			else
			{
				lst = lst->next;
				t++;
			}
		}
		else if (t > (i / 2))
		{	
			if (lst->number == j)
			{
				lst = *var_a;
				lst->previous = NULL;
				while (i > t)
				{
					rra(&lst, head_a);
					i--;
				}
				return ;
			}
			else
			{
				lst = lst->next;
				t++;
			}
		}
		else
		{
			lst = lst->next;
			t++;
		}
	}
}


void	bestmovea(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b, int j)
{
	t_ps	*lst_a;
	t_ps	*lst_b;
	int i;
	int i_value;
	int t;
	int lenght;

	lst_a = *var_a;
	lst_b = *var_b;
	i = 0;
	t = 0;
	i_value = 0;
	lenght = 0;
	while (lst_a)
	{
		lenght++;
		lst_a = lst_a->next;
	}
	lst_a = *head_a;
	while (lst_b)
	{
		lst_a = *head_a;
		i_value = lst_b->number;
		i = 0;
		while (lst_a)
		{
			if (lst_a->number < i_value)
			{
				lst_a = lst_a->next;
				i++;
				if (!lst_a)
				{
					lst_a = *var_a;
					t = 0;
					if (lst_a->number > i_value)
					{
						lst_b->bestmovea = 0;
						break ;
					}
					while (lst_a)
					{
						if (lst_a->number == j)
						{
							if (t < (lenght / 2))
								lst_b->bestmovea = t;
							else
								lst_b->bestmovea = (lenght - t + 1) * -1;
							break ;
						}
						t++;
						lst_a = lst_a->next;
					}
					break ;
				}
				if (lst_a->number > i_value)
				{
					if (i < (lenght / 2))
						lst_b->bestmovea = i;
					else
						lst_b->bestmovea = (lenght - i + 1) * -1;
					break ;
				}
			}
			else
			{
				lst_a = lst_a->next;
				i++;
			}
		}
		lst_b = lst_b->next;
	}
}