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
	int i;
	int j;

	i = 1;
		
	j = 0;
	if (argc > 2)
	{
		while (argv[i])
		{
			push(&var_a, &head_a, atoi(argv[i]));	
			i++;
		}

		// rrb(&var_b, &head_b);
		sa(&var_a, &head_a);
		reset(&var_a, &head_a, &var_b, &head_b);
		pb(&var_a, &head_a, &var_b, &head_b);
		reset(&var_a, &head_a, &var_b, &head_b);
		sb(&var_b, &head_b);
		//reset(&var_a, &head_a, &var_b, &head_b);
		while (var_a)
		{
			printf("%d\n", var_a->number);
			var_a = var_a->next;
		}
		printf("----\n");
		while (var_b)
		{
			printf("%d\n", var_b->number);
			var_b = var_b->next;
		}
		// reset(&var_a, &head_a, &var_b, &head_b);	
	}
	
	return 0;
}