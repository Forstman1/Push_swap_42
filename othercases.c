/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threecase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:57:48 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/22 15:57:50 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rules(int first, int second, int third, t_stack *stacks)
{
	if ((first < second) && (second < third))
		return ;
	else if ((first > third) && (first < second) && (second > first))
	{
		stacks->var_a->previous = NULL;
		rra(&stacks->var_a, &stacks->head_a);
	}
	else if ((first < third) && (first > second) && (second < third))
	{
		sa(&stacks->var_a, &stacks->head_a);
	}
	else if ((first > third) && (first > second) && (second < third))
	{
		ra(&stacks->var_a, &stacks->head_a);
	}
	else if ((first > third) && (first > second) && (second > third))
	{
		sa(&stacks->var_a, &stacks->head_a);
		stacks->var_a->previous = NULL;
		rra(&stacks->var_a, &stacks->head_a);
	}
	else if ((first < third) && (first < second) && (third < second))
	{
		sa(&stacks->var_a, &stacks->head_a);
		ra(&stacks->var_a, &stacks->head_a);
	}
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
	rules(first, second, third, stacks);
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
	lst_a = stacks->head_a;
	lst_b = stacks->head_b;
	if (lst_a->number == j)
		ra(&stacks->var_a, &stacks->head_a);
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

void	free_parsing(char	**splited)
{
	int		i;
	char	*tmp;

	i = 0;
	while (splited[i])
	{
		tmp = splited[i];
		free(tmp);
		i++;
	}
}

void	free_everything(t_stack	*stacks)
{
	t_ps	*tmp;
	t_ps	*lst;

	lst = stacks->var_a;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	lst = stacks->var_b;
}
