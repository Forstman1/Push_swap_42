/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:42:18 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/09 15:42:19 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	pushtoa(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b, int j)
{
	t_ps	*lst_a;
	t_ps	*lst_b;

	lst_a = *var_a;
	lst_b = *var_b;

	while (lst_b)
	{
		lst_b = *head_b;
		if (lst_b->bestmovea < 0)
		{
			lst_a = *head_a;
			while (lst_b->bestmovea < 0)
			{
				rra(&lst_a, head_a);
				lst_b->bestmovea += 1;
			}
			pa(&lst_a, head_a, &lst_b, head_b);
			lst_a = *head_a;
			sa(&lst_a, head_a);
			lst_b = *head_b;
			lst_a = *head_a;
			while (lst_a)
			{
				sortingcount(&lst_a, head_a, j);
				lst_a = lst_a->next;
			}
			lst_a = *head_a;
			bestmovea(&lst_a, head_a, &lst_b, head_b);
			lst_a = *head_a;
		}
		else
		{
			lst_a = *head_a;
			while (lst_b->bestmovea > 0)
			{
				ra(&lst_a, head_a);
				lst_b->bestmovea -= 1;
			}
			pa(&lst_a, head_a, &lst_b, head_b);
			lst_a = *head_a;
			lst_b = *head_b;
			while (lst_a)
			{
				sortingcount(&lst_a, head_a, j);
				lst_a = lst_a->next;
			}
			lst_a = *head_a;
			bestmovea(&lst_a, head_a, &lst_b, head_b);
			lst_a = *head_a;
		}
	}
}