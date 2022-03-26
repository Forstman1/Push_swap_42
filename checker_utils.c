/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:16:25 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/18 16:16:26 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker1/checker.h"
#include <unistd.h>

char	*get_next_line(void)
{
	char	buffer[600000];
	char	buff;
	int		nbyte;
	int		i;
	int		j;

	nbyte = 1;
	j = 0;
	i = 0;
	while (nbyte > 0)
	{
		nbyte = read(0, &buff, 1);
		if (nbyte <= 0)
			break ;
		buffer[j++] = buff;
		if (buff == '\n')
			break ;
	}
	buffer[j] = '\0';
	if (j == 0 && nbyte <= 0)
		return (NULL);
	return (ft_strdup(buffer));
}

void	check_everything(t_stack	*stacks)
{
	if (stacks->var_b)
	{
		write(1, "KO\n", 3);
		free_everything(stacks);
		return ;
	}
	check_sorting(stacks);
	free_everything(stacks);
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
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

void	checkmaxint(char	**splited, int t)
{
	int			i;
	long long	*array;

	i = 0;
	array = NULL;
	array = (long long *)malloc(sizeof(long long) * t);
	while (splited[i])
	{
		array[i] = ft_atoi(splited[i]);
		i++;
	}
	i = 0;
	while (i < t)
	{
		if (array[i] >= 2147483648 || array[i] <= -2147483648)
		{
			free(array);
			free_parsing(splited);
			error();
		}
		i++;
	}
	free(array);
}

int	stack_a_rules(t_stack *stacks, char	*str)
{
	if (ft_strncmp(str, "sa\n", 6) == 0)
	{
		sa(&stacks->var_a, &stacks->head_a);
		return (1);
	}
	else if (ft_strncmp(str, "ra\n", 6) == 0)
	{
		ra(&stacks->var_a, &stacks->head_a);
		return (1);
	}
	else if (ft_strncmp(str, "pa\n", 6) == 0)
	{
		pa(&stacks->var_a, &stacks->head_a, &stacks->var_b, &stacks->head_b);
		return (1);
	}
	else if (ft_strncmp(str, "rra\n", 6) == 0)
	{
		stacks->var_a->previous = NULL;
		rra(&stacks->var_a, &stacks->head_a);
		return (1);
	}
	return (0);
}
