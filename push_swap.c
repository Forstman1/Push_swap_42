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

int main(int argc, char *argv[])
{
	t_ps	*var_a;
	t_ps	*var_b;
	t_ps	*head_a;
	t_ps	*head_b;
	t_ps	*tail_a;
	t_ps	*tail_b;
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
				n = t;
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
		if (n < (t / 2))
		{
			while ((n - 1) > 0)
			{
				ra(&var_a, &head_a);
				n--;
			}	
		}
		else
		{
			while (t >= n)
			{
				rra(&var_a, &head_a);
				t--;
			}
		}
		lis(&var_a, &head_a);
		reset(&var_a, &head_a, &var_b, &head_b);
		var_a->subsequence = -1;
		pushingtostackb(&var_a, &head_a, &var_b, &head_b);
		reset(&var_a, &head_a, &var_b, &head_b);
		
		
		
		
		
		
		while (var_a)
		{
			printf("%d--stack a--%d\n", var_a->number, var_a->lic);
			var_a = var_a->next;
		}
		while (var_b)
		{
			printf("%d--stack b--%d\n", var_b->number, var_b->lic);
			var_b = var_b->next;
		}
		printf("%d\n", j);
	}

	return (0);
}