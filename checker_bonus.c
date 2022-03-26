/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:56:06 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/18 15:56:07 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "checker1/checker.h"

void	errors(t_stack *stacks)
{
	write(1, "ERROR\n", 6);
	free_everything(stacks);
	exit(0);
}

void	check_rules(char	*str, t_stack *stacks)
{
	stacks->var_a = stacks->head_a;
	if (stack_a_rules(stacks, str))
		return ;
	if (ft_strncmp(str, "pb\n", 6) == 0)
		pb(&stacks->var_a, &stacks->head_a, &stacks->var_b, &stacks->head_b);
	else if (ft_strncmp(str, "sb\n", 6) == 0)
		sb(&stacks->var_b, &stacks->head_b);
	else if (ft_strncmp(str, "rb\n", 6) == 0)
		rb(&stacks->var_b, &stacks->head_b);
	else if (ft_strncmp(str, "rrb\n", 6) == 0)
	{
		stacks->var_b->previous = NULL;
		rrb(&stacks->var_b, &stacks->head_b);
	}
	else if (ft_strncmp(str, "rr\n", 6) == 0)
		rr(&stacks->var_a, &stacks->head_a, &stacks->var_b, &stacks->head_b);
	else if (ft_strncmp(str, "rrr\n", 6) == 0)
		rrr(&stacks->var_a, &stacks->head_a, &stacks->var_b, &stacks->head_b);
	else
		errors(stacks);
}

void	check_sorting(t_stack	*stacks)
{
	int		last_number;
	t_ps	*lst;

	stacks->var_a = stacks->head_a;
	lst = stacks->var_a;
	while (lst->next)
	{
		last_number = lst->number;
		lst = lst->next;
		if (last_number > lst->number)
		{
			write(1, "KO\n", 3);
			return ;
		}
	}
	write(1, "OK\n", 3);
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

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	stacks;
	char	*rules;
	char	**splited;

	i = 1;
	if (argc > 1)
	{
		splited = parsings(argv, &i);
		while (--i >= 0)
			push(&stacks.var_a, &stacks.head_a, ft_atoi(splited[i]));
		free_parsing(splited);
		rules = get_next_line();
		while (rules)
		{
			check_rules(rules, &stacks);
			free(rules);
			rules = NULL;
			rules = get_next_line();
		}
		check_everything(&stacks);
		return (0);
	}
}
