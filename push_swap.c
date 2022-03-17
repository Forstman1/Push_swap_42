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

void ft_lstadd(t_ps **lst, t_ps **head, t_ps *new)
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

void reset2(t_stack	*stacks)
{
	stacks->var_a = stacks->head_a;
	stacks->var_b = stacks->head_b;
}

void	reset(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b)
{
	*var_a = *head_a;
	*var_b = *head_b;
}

void resetindex(t_ps **var)
{
	t_ps *var_a;
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

int smallistnumber(t_ps **var_a)
{
	t_ps *lst;
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
	t_stack	stacks;
	char	*str;
	char	**splited;
	int		i;
	int		j;

	i = 1;
	str = "";
	if (argc > 2)
	{
		while (argv[i])
		{
			checkvalid(argv[i]);
			str = ft_strjoin(str, argv[i]);
			str = ft_strjoin(str, " ");
			i++;
		}
		splited = ft_split(str, ' ');
		checkduplicate(splited, i);
		i = 0;
		while (splited[i])
			i++;
		while (--i >= 0)
			push(&stacks.var_a, &stacks.head_a, ft_atoi(splited[i]));
		j = smallistnumber(&stacks.var_a);
		reset2(&stacks);
		resetindex(&stacks.var_a);
		reset_to_smallist_number(&stacks.var_a, &stacks.head_a, j);
		reset2(&stacks);
		while (stacks.var_a)
		{
			stacks.var_a->lic = 0;
			stacks.var_a = stacks.var_a->next;
		}
		reset2(&stacks);
		lis(&stacks.var_a, &stacks.head_a);
		reset2(&stacks);
		stacks.var_a->subsequence = 0;
		pushingtostackb(&stacks);
		reset2(&stacks);
		stack_sorting(&stacks);
		reset2(&stacks);
		reset_to_smallist_number(&stacks.var_a, &stacks.head_a, j);
	}
	return (0);
}