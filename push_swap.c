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

void	resetindex(t_ps	**var)
{
	t_ps	*var_a;
	int t;

	t = -1;
	var_a = *var;
	while (var_a)
	{
		var_a->count = t + 1;
		t++;
		var_a = var_a->next;
	}
}

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


void	reset_to_smallist_number_test(t_ps	**var_a, t_ps	**head_a, t_ps	**head_fake, t_ps **tails, t_ps **tmp1, t_ps **tmp2, int j)
{
	t_ps	*lst;

	lst = *var_a;
	while (lst)
	{
		if (lst->number == j)
		{
			*head_fake = lst;
			lst = lst->previous;
			if (!lst)
			{
				lst = *var_a;
				while (lst->next)
					lst = lst->next;
				*tmp1 = lst;
				*tmp2 = *head_fake;
				*var_a = *head_a;
				return ;
			}
			*tails = lst;
			while (lst->previous)
				lst = lst->previous;
			*tmp2 = lst;
			lst = *head_a;
			while (lst->next)
				lst = lst->next;
			*tmp1 = lst;
			return ;
		}
		lst = lst->next;
	}
}

int	smallistnumber(t_ps	**var_a)
{
	t_ps	*lst;
	int j;

	j = 0;
	lst = *var_a;
	j = lst->number;
	while (lst)
	{
		if (j > lst->number)
		{
			j = lst->number;
			lst = lst->next;
		}
		else
			lst = lst->next;
	}
	return (j);
}

int main(int argc, char *argv[])
{
	t_ps	*var_a;
	t_ps	*var_b;
	t_ps	*head_a;
	t_ps	*head_b;
	t_ps	*head_fake;
	t_ps	*tails;
	t_ps	*tmp1;
	t_ps	*tmp2;
	int i;
	int j;

	i = 1;
	if (argc > 2)
	{
		while (argv[i])
			i++;
		i--;	
		while (i > 0)
		{
			push(&var_a, &head_a, atoi(argv[i]));
			i--;
		}
		j = smallistnumber(&var_a);
		reset(&var_a, &head_a, &var_b, &head_b);
		resetindex(&var_a);
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
		var_a->subsequence = 0;
		pushingtostackb(&var_a, &head_a, &var_b, &head_b);
		reset(&var_a, &head_a, &var_b, &head_b);
		stack_sorting(&var_a, &head_a, &var_b, &head_b, j);
		reset(&var_a, &head_a, &var_b, &head_b);
		reset_to_smallist_number(&var_a, &head_a, j);
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