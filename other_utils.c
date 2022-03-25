/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:31:58 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/25 20:31:59 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checksorted(t_stack	*stacks)
{
	t_ps	*lst;
	int		last_number;

	last_number = 0;
	lst = stacks->var_a;
	while (lst->next)
	{
		last_number = lst->number;
		lst = lst->next;
		if (last_number > lst->number)
			return (0);
	}
	return (1);
}

void	error_duplicate(char	**splited, int *array)
{
	free_parsing(splited);
	free(array);
	error();
}
