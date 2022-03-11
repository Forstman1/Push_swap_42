/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:23:33 by sahafid           #+#    #+#             */
/*   Updated: 2022/02/26 12:23:34 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void	ft_lstadd_front(t_ps **lst, t_ps **head, t_ps *new)
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

void	reset(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b)
{
	*var_a = *head_a;
	*var_b = *head_b;
}

// void	resetindex(t_ps	**var)
// {
// 	t_ps	*var_a;
// 	int t;

// 	t = -1;
// 	var_a = *var;
// 	while (var_a)
// 	{
// 		var_a->count = t + 1;
// 		t++;
// 		var_a = var_a->next;
// 	}
// }

void	reset_to_smallist_number(t_ps	**var_a, t_ps	**head_a, int j)
{
	t_ps	*lst_a;

	lst_a = *head_a;
	while (lst_a)
	{
		sortingcount(&lst_a, head_a, j);
		lst_a = lst_a->next;
	}
}

int main(int argc, char *argv[])
{
	t_ps	*var_a;
	t_ps	*var_b;
	t_ps	*head_a;
	t_ps	*head_b;
	t_ps	*tail_a;
	int i;
	int j;
	int t;
	int n;

	i = 1;
	t = -1;
	if (argc > 2)
	{
		while (argv[i])
			i++;
		i--;	
		while (i > 0)
		{
			push(&var_a, &head_a, &tail_a, atoi(argv[i]));
			i--;
		}
		j = var_a->number;
		while (var_a)
		{
			if (j > var_a->number)
			{
				j = var_a->number;
				var_a->count = t + 1;
				t++;
				var_a = var_a->next;
			}
			else
			{
				var_a->count = t + 1;
				t++;
				var_a = var_a->next;
			}
		}
		reset(&var_a, &head_a, &var_b, &head_b);
		reset_to_smallist_number(&var_a, &head_a, j);
		reset(&var_a, &head_a, &var_b, &head_b);
		while (var_a)
		{
			var_a->lic = 0;
			var_a = var_a->next;
		}
		reset(&var_a, &head_a, &var_b, &head_b);
		lis(&var_a, &head_a);
		reset(&var_a, &head_a, &var_b, &head_b);
		var_a->subsequence = -1;
		pushingtostackb(&var_a, &head_a, &var_b, &head_b);
		reset(&var_a, &head_a, &var_b, &head_b);
		while (var_a)
		{
			printf("%d--stack a--%d---%d\n", var_a->number, var_a->subsequence, var_a->count);
			//printf("'\n");
			var_a = var_a->next;
		}
		while (var_b)
		{
			printf("%d--stack b--%d\n", var_b->number, var_b->subsequence);
			//printf("'\n");
			var_b = var_b->next;
		}
		reset(&var_a, &head_a, &var_b, &head_b);
		bestmoveinb(&var_b, &head_b);
		reset(&var_a, &head_a, &var_b, &head_b);
		reset_to_smallist_number(&var_a, &head_a, j);
		bestmovea(&var_a, &head_a, &var_b, &head_b);
		reset(&var_a, &head_a, &var_b, &head_b);
		bestscore(&var_a, &head_a, &var_b, &head_b);
		reset(&var_a, &head_a, &var_b, &head_b);
		stack_sorting(&var_a, &head_a, &var_b, &head_b, j);
		reset(&var_a, &head_a, &var_b, &head_b);
		// while (var_a)
		// {
		// 	printf("%d--stack a--%d\n", var_a->number, var_a->lic);
		// 	//printf("'\n");
		// 	var_a = var_a->next;
		// }
		// printf("'\n");
		// while (var_b)
		// {
		// 	printf("%d--stack b--%d\n", var_b->number, var_b->lic);
		// 	var_b = var_b->next;
		// }
	}
	return (0);
}