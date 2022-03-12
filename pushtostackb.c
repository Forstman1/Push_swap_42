/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushtostackb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:15:27 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/12 14:15:29 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


// void	pushingtostackb(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b)
// {
// 	int caase;
// 	t_ps	*lst_a;
// 	t_ps	*lst_b;
// 	int i;
// 	int j;
// 	int t;

// 	i = 0;
// 	t = 0;
// 	caase = 0;
// 	lst_a = *var_a;
// 	lst_b = *var_b;
// 	while (lst_a->next)
// 	{
// 		if (i < lst_a->index)
// 			i = lst_a->index;
// 		lst_a = lst_a->next;
// 	}
// 	j = lst_a->count;
// 	while (lst_a->previous)
// 	{
// 		if (i == lst_a->index)
// 		{
// 			lst_a->lic = 1;
// 			caase = lst_a->subsequence;
// 			while (lst_a)
// 			{
// 				if (caase == lst_a->count)
// 				{
// 					lst_a->lic = 1;
// 					caase = lst_a->subsequence;
// 				}
// 				lst_a = lst_a->previous;
// 			}
// 			break ;
// 		}
// 		lst_a = lst_a->previous;
// 	}
// 	i = 0;
//	lst_a = *var_a;
// 	while (lst_a)
// 	{
// 		if (i < (j / 2))
// 		{
// 			if (lst_a->lic == 0)
// 			{
// 				reset(&lst_a, head_a, var_b, head_b);
// 				while (i > 0)
// 				{
// 					ra(&lst_a, head_a);
// 					i--;
// 				}
// 				pb(&lst_a, head_a, var_b, head_b);
// 				reset(&lst_a, head_a, var_b, head_b);
// 				i = 0;
// 			}
// 			else
// 			{
// 				lst_a = lst_a->next;
// 				i++;
// 			}
// 		}
// 		else
// 			if (lst_a->lic == 0)
// 			{
// 				i = j;
// 				reset(&lst_a, head_a, var_b, head_b);
// 				lst_a->previous = NULL;
// 				while (i > (j / 2))
// 				{
// 					rra(&lst_a, head_a);
// 					i--;
// 				}
// 				pb(&lst_a, head_a, var_b, head_b);
// 				reset(&lst_a, head_a, var_b, head_b);
// 				j = 0;
// 				while (lst_a)
// 				{
// 					j++;
// 					lst_a = lst_a->next;
// 				}
// 				reset(&lst_a, head_a, var_b, head_b);
// 				i = 0;
// 			}
// 			else
// 			{
// 				lst_a = lst_a->next;
// 				i++;
// 			}
// 	}
// }


static int	smallistscore(t_ps	**var_a)
{
	t_ps	*lst_a;
	int		i;

	lst_a = *var_a;
	i = 0;
	while (lst_a)
	{
		if (lst_a->lic == 0)
		{
			i = lst_a->score;
			while (lst_a)
			{
				if (lst_a->lic == 0)
				{
					if (lst_a->score < i)
						i = lst_a->score;
				}
				lst_a = lst_a->next;
			}
			return (i);
		}
		lst_a = lst_a->next;
	}
}

void	pushingtostackb(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b)
{
	int caase;
	t_ps	*lst_a;
	t_ps	*lst_b;
	int i;
	int j;
	int t;

	i = 0;
	t = 0;
	caase = 0;
	lst_a = *var_a;
	lst_b = *var_b;
	while (lst_a->next)
	{
		if (i < lst_a->index)
			i = lst_a->index;
		lst_a = lst_a->next;
	}
	j = lst_a->count;
	while (lst_a->previous)
	{
		if (i == lst_a->index)
		{
			lst_a->lic = 1;
			caase = lst_a->subsequence;
			while (lst_a)
			{
				if (caase == lst_a->count)
				{
					lst_a->lic = 1;
					caase = lst_a->subsequence;
				}
				lst_a = lst_a->previous;
			}
			break ;
		}
		lst_a = lst_a->previous;
	}
	i = 0;
	bestscore_for_a(var_a, head_a);
	lst_a = *var_a;
	while (lst_a)
	{
		if (lst_a->lic == 0)
		{
			if (lst_a->bestmovea == 0)
				lst_a->score = 0;
			else if (lst_a->bestmovea > 0)
				lst_a->score = lst_a->bestmovea;
			else
				lst_a->score = lst_a->bestmovea * -1;
		}
		lst_a = lst_a->next;
	}
	lst_a = *var_a;

	while (lst_a)
	{
		*var_a = *head_a;
		i = smallistscore(var_a);
		//printf("ana hna\n");
		while (lst_a)
		{
			if (lst_a->lic == 0)
			{
				if (lst_a->score == i)
					break ;
			}
			lst_a = lst_a->next;
		}
		if (lst_a->lic == 0)
		{
			if (lst_a->bestmovea == 0)
				pb(var_a, head_a, var_b, head_b);
			else if (lst_a->bestmovea > 0)
			{
				while (lst_a->bestmovea > 0)
				{
					ra(var_a, head_a);
					lst_a->bestmovea--;
				}
				pb(var_a, head_a, var_b, head_b);
			}
			else if (lst_a->bestmovea < 0)
			{
				(*var_a)->previous = NULL;
				while (lst_a->bestmovea < 0)
				{
					rra(var_a, head_a);
					lst_a->bestmovea++;
				}
				pb(var_a, head_a, var_b, head_b); 
			}
			lst_a = *var_a;
		}
		else if (lst_a->lic == 1)
			lst_a = lst_a->next;
	}
	//lst_a = *var_a;
}