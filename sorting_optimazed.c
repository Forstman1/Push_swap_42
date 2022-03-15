/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_optimazed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:03:54 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/10 20:03:57 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	bestscore(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b)
{
	t_ps	*lst_a;
	t_ps	*lst_b;
	int		tmp;

	lst_a = *var_a;
	lst_b = *var_b;
	tmp = 0;

	while (lst_b)
	{
		if (lst_b->bestmovea >= 0)
		{
			if (lst_b->bestmoveb >= 0)
			{
				if (lst_b->bestmovea == lst_b->bestmoveb)
					lst_b->score = lst_b->bestmovea;
				else
				{
					if (lst_b->bestmovea > lst_b->bestmoveb)
					{
						tmp = lst_b->bestmovea - lst_b->bestmoveb;
						lst_b->score = tmp + lst_b->bestmoveb;
					}
					else
					{
						tmp = lst_b->bestmoveb - lst_b->bestmovea;
						lst_b->score = tmp + lst_b->bestmovea;
					}
				}
				lst_b = lst_b->next;
			}
			else
			{
				lst_b->score = lst_b->bestmovea + (lst_b->bestmoveb * -1);
				lst_b = lst_b->next;
			}
		}
		else
		{
			if (lst_b->bestmoveb >= 0)
				lst_b->score = (lst_b->bestmovea * -1) + lst_b->bestmoveb;
			else
			{
				if (lst_b->bestmovea == lst_b->bestmoveb)
					lst_b->score = lst_b->bestmovea * -1;
				else
				{
					if (lst_b->bestmovea > lst_b->bestmoveb)
					{
						tmp = (lst_b->bestmoveb * -1) - (lst_b->bestmovea * -1);
						lst_b->score = tmp + (lst_b->bestmovea * -1);
					}
					else
					{
						tmp = (lst_b->bestmovea * -1) - (lst_b->bestmoveb * -1);
						lst_b->score = tmp + (lst_b->bestmoveb * -1);
					}
				}
			}
			lst_b = lst_b->next;
		}
	}
}

void	pushtoaoptimazed(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b, int j)
{
	t_ps	*lst_a;
	t_ps	*lst_b;
	int i;
	int t;

	lst_a = *var_a;
	lst_b = *var_b;
	t = 0;
	lst_a = *var_a;
	lst_b = *var_b;
	i = lst_b->score;
	while (lst_b)
	{
		if (lst_b->score < i)
			i = lst_b->score;
		lst_b = lst_b->next;
	}
	lst_b = *head_b;
	while (lst_b)
	{
		if (lst_b->score == i)
			break ;
		lst_b = lst_b->next;
	}
	reset(var_a, head_a, var_b, head_b);
	while (lst_b->bestmovea > 0 && lst_b->bestmoveb > 0)
	{
		rr(var_a, head_a, var_b, head_b);
		lst_b->bestmovea--;
		lst_b->bestmoveb--;
	}	
	reset(var_a, head_a, var_b, head_b);
	(*var_b)->previous = NULL;
	(*var_a)->previous = NULL;
	while (lst_b->bestmovea < -1 && lst_b->bestmoveb < 0)
	{
		rrr(var_a, head_a, var_b, head_b);
		lst_b->bestmovea++;
		lst_b->bestmoveb++;
	}
	reset(var_a, head_a, var_b, head_b);
	while (lst_b->bestmovea < -1)
	{
		rra(var_a, head_a);
		lst_b->bestmovea += 1;
	}
	reset(var_a, head_a, var_b, head_b);
	while (lst_b->bestmovea > 0)
	{
		ra(var_a, head_a);
		lst_b->bestmovea -= 1;
	}
	reset(var_a, head_a, var_b, head_b);
	(*var_b)->previous = NULL;
	while (lst_b->bestmoveb < 0)
	{
		rrb(var_b, head_b);
		lst_b->bestmoveb += 1;
	}
	reset(var_a, head_a, var_b, head_b);
	while (lst_b->bestmoveb > 1)
	{
		rb(var_b, head_b);
		lst_b->bestmoveb -= 1;
	}
	if (lst_b->bestmoveb == 1)
	{
		sb(var_b, head_b);
		lst_b->bestmovea -= 1;
	}
}

void	stack_sorting(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b, int j)
{
	t_ps	*lst_a;
	t_ps	*lst_b;

	lst_a = *var_a;
	lst_b = *var_b;
	while (lst_b)
	{
		bestmovea(&lst_a, head_a, &lst_b, head_b, j);
		bestmoveinb(&lst_b, head_b);
		bestscore(&lst_a, head_a, &lst_b, head_b);
		lst_b = *head_b;
		lst_a = *var_a;
		// sleep(1);
		// while (lst_a)
		// {
		// 	printf("%d--stack a--%d\n", lst_a->number, lst_a->count);
		// 	//printf("'\n");
		// 	lst_a = lst_a->next;
		// }
		// printf("'\n");
		// while (lst_b)
		// {
		// 	printf("%d--stack b--|%d---|%d---|%d\n", lst_b->number, lst_b->bestmovea, lst_b->bestmoveb, lst_b->score);
		// 	lst_b = lst_b->next;
		// }
		// printf("---------\n");
		lst_b = *head_b;
		lst_a = *var_a;
		pushtoaoptimazed(var_a, head_a , &lst_b, head_b, j);
		//reset(var_a, head_a, var_b, head_b);
		pa(&lst_a, head_a, &lst_b, head_b);
		*var_a = *head_a;
		lst_a = *var_a;
		lst_b = *head_b;
	}
}