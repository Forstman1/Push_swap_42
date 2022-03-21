/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:31:27 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/16 14:31:28 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error(void)
{
	printf("ERROR\n");
	exit(0);
}

void	checkvalid(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			j++;
		}
		else if (isdigit(str[i]))
			i++;
		else if ((str[i] == '+' && isdigit(str[i - 1])) \
			|| (str[i] == '-' && isdigit(str[i - 1])))
			error();
		else if (str[i] == '-' && isdigit(str[i + 1]))
			i++;
		else if (str[i] == '+' && isdigit(str[i + 1]))
			i++;
		else
			error();
	}
	if (i == j)
		error();
	if (i == 0)
		error();
}

void	checkduplicate(char	**splited, int i)
{
	int	*array;
	int	j;
	int	t;

	j = 0;
	t = 0;
	array = (int *)malloc(sizeof(int) * (i - 1));
	i = 0;
	while (splited[i])
	{
		array[i] = ft_atoi(splited[i]);
		i++;
	}
	while (j - 1 < i)
	{
		t = j + 1;
		while (t < i)
		{
			if (array[j] == array[t])
				error();
			t++;
		}
		j++;
	}
}
