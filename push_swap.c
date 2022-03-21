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
#include "libft/libft.h"
#include <ctype.h>

void	resetindex(t_ps **var)
{
	t_ps	*var_a;
	int		t;

	t = -1;
	var_a = *var;
	while (var_a)
	{
		var_a->count = t + 1;
		t++;
		var_a = var_a->next;
	}
}

int	smallistnumber(t_ps **var_a)
{
	t_ps	*lst;
	int		j;

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

void	sortingpart(t_stack *stacks, int j)
{
	resetindex(&stacks->var_a);
	reset_to_smallist_number(&stacks->var_a, &stacks->head_a, j);
	while (stacks->var_a)
	{
		stacks->var_a->lic = 0;
		stacks->var_a = stacks->var_a->next;
	}
	reset2(stacks);
	lis(&stacks->var_a, &stacks->head_a);
	pushingtostackb(stacks);
	stack_sorting(stacks, j);
	reset_to_smallist_number(&stacks->var_a, &stacks->head_a, j);
}

void	threecases(t_stack *stacks)
{
	int		first;
	int		second;
	int		third;
	t_ps	*lst_a;

	lst_a = stacks->var_a;
	first = lst_a->number;
	lst_a = lst_a->next;
	second = lst_a->number;
	lst_a = lst_a->next;
	third = lst_a->number;
	lst_a = stacks->var_a;
	if ((first < second) && (second < third))
		return ;
	else if ((first > third) && (first < second) && (second > first))
	{
		stacks->var_a->previous = NULL;
		rra(&stacks->var_a, &stacks->head_a);
		return ;
	}
	else if ((first < third) && (first > second) && (second < third))
	{
		sa(&stacks->var_a, &stacks->head_a);
		return ;
	}
	else if ((first > third) && (first > second)  && (second < third))
	{
		ra(&stacks->var_a, &stacks->head_a);
		return ;
	}
	else if ((first > third) && (first > second) && (second > third))
	{
		sa(&stacks->var_a, &stacks->head_a);
		stacks->var_a->previous = NULL;
		rra(&stacks->var_a, &stacks->head_a);
		return ;
	}
	else if ((first < third) && (first < second) && (third < second))
	{
		sa(&stacks->var_a, &stacks->head_a);
		ra(&stacks->var_a, &stacks->head_a);
		return ;
	}
}

void	fivecases(t_stack	*stacks, int j)
{
	int		i;
	int		t;
	t_ps	*lst_a;
	t_ps	*lst_b;

	i = 2;
	t = 2;
	lst_a = stacks->head_a;
	lst_b = stacks->head_b;
	if (lst_a->number == j)
		rra(&stacks->var_a, &stacks->head_a);
	while (i > 0)
	{
		pb(&stacks->var_a, &stacks->head_a, &stacks->var_b, &stacks->head_b);
		i--;
	}
	threecases(stacks);
	reset2(stacks);
	stack_sorting(stacks, j);
	reset_to_smallist_number(&stacks->var_a, &stacks->head_a, j);
}

void	cases(t_stack	*stacks, int j)
{
	int		i;
	t_ps	*lst;

	i = 0;
	lst = stacks->head_a;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	if (i == 3)
		threecases(stacks);
	else if (i == 5)
		fivecases(stacks, j);
	else
		sortingpart(stacks, j);
}

int	main(int argc, char *argv[])
{
	t_stack	stacks;
	char	**splited;
	int		i;
	int		j;

	i = 1;
	if (argc > 1)
	{
		splited = parsing(argv, &i);
		j = i;
		while (--i >= 0)
			push(&stacks.var_a, &stacks.head_a, ft_atoi(splited[i]));
		j = smallistnumber(&stacks.var_a);
		cases(&stacks, j);
		return (0);
	}
	else
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
}
