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
		free_parsing(splited);
		j = smallistnumber(&stacks.var_a);
		cases(&stacks, j);
		free_everything(&stacks);
		return (0);
	}
}
