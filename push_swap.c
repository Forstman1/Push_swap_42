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
	int i_value;
	int pivote;
	int j;
	int j_value;

	i = 1;
	i_value = 0;
	j_value = 0;
	j = 0;
	pivote = 0;
	if (argc > 2)
	{
		while (argv[i])
		{
			push(&var_a, &head_a, &tail_a, atoi(argv[i]));	
			i++;
		}
		i = 0;
		j = 0;
		pivote = var_a->number;
		while (var_a)
		{
			var_a = var_a->next;
			i_value = var_a->number;
			if (i_value > pivote)
			{
				
				reset(&var_a, &head_a, &var_b, &head_b);
				while (i >= 0)
				{
					//reset(&var_a, &head_a, &var_b, &head_b);
					pb(&var_a, &head_a, &var_b, &head_b);
				 	i--;
				}
				rra(&var_a, &head_a);
				sa(&var_a, &head_a);
				ra(&var_a, &head_a);
				break ;
			}
			else
				i++;
		}
		reset(&var_a, &head_a, &var_b, &head_b);
		while (var_a)
		{
			printf("%d--stack a--\n", var_a->number);
			var_a = var_a->next;
		}
		while (var_b)
		{
			printf("%d--stack b--\n", var_b->number);
			var_b = var_b->next;
		}
	}

	return 0;
}