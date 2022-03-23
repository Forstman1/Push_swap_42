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
#include "checker/checker.h"

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
	exit(0);
}

void	check_rules(char	*str, t_stack *stacks)
{
	if (ft_strncmp(str, "sa\n", 6) == 0)
		sa(&stacks->var_a, &stacks->head_a);
	else if (ft_strncmp(str, "ra\n", 6) == 0)
		ra(&stacks->var_a, &stacks->head_a);
	else if (ft_strncmp(str, "pa\n", 6) == 0)
		pa(&stacks->var_a, &stacks->head_a, &stacks->var_b, &stacks->head_b);
	else if (ft_strncmp(str, "pb\n", 6) == 0)
		pb(&stacks->var_a, &stacks->head_a, &stacks->var_b, &stacks->head_b);
	else if (ft_strncmp(str, "rra\n", 6) == 0)
		rra(&stacks->var_a, &stacks->head_a);
	else if (ft_strncmp(str, "sb\n", 6) == 0)
		sb(&stacks->var_b, &stacks->head_b);
	else if (ft_strncmp(str, "rb\n", 6) == 0)
		rb(&stacks->var_b, &stacks->head_b);
	else if (ft_strncmp(str, "rrb\n", 6) == 0)
		rrb(&stacks->var_b, &stacks->head_b);
	else if (ft_strncmp(str, "rr\n", 6) == 0)
		rr(&stacks->var_a, &stacks->head_a, &stacks->var_b, &stacks->head_b);
	else if (ft_strncmp(str, "rrr\n", 6) == 0)
		rrr(&stacks->var_a, &stacks->head_a, &stacks->var_b, &stacks->head_b);
	else
	{
		write(1, "ERROR\n", 6);
		free_everything(stacks);
	}
}

void	check_sorting(t_stack	*stacks)
{
	int		last_number;
	t_ps	*lst;

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
		if (stacks.var_b)
		{
			write(1, "KO\n", 3);
			free_everything(&stacks);
			return (0);
		}
		check_sorting(&stacks);
		free_everything(&stacks);
		return (0);
	}
}
