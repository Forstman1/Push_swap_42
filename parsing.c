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

#include "push_swap.h"

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
		else if ((str[i] == '+' || str[i] == '-') && isdigit(str[i + 1]))
			i++;
		else
			error();
	}
	if (i == j)
		error();
}

void	checkduplicate(char	**splited, int i)
{
	int	*array;
	int	j;
	int	t;

	j = 0;
	array = NULL;
	array = (int *)malloc(sizeof(int) * i);
	i = 0;
	while (splited[i])
	{
		array[i] = ft_atoi(splited[i]);
		i++;
	}
	while (j < i)
	{
		t = 0;
		while (t < i)
		{
			if (array[j] == array[t] && t != j)
				error_duplicate(splited, array);
			t++;
		}
		j++;
	}
	free(array);
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

char	**parsing_utils(char	**splited, char	**argv, int i)
{
	char	*tmp;
	char	*str;

	str = NULL;
	while (argv[i])
	{
		checkvalid(argv[i]);
		if (!str)
			str = ft_strdup(argv[i]);
		else
		{
			tmp = str;
			str = ft_strjoin(str, argv[i]);
			free(tmp);
		}
		tmp = str;
		str = ft_strjoin(str, " ");
		free(tmp);
		i++;
	}
	splited = ft_split(str, ' ');
	free(str);
	return (splited);
}

char	**parsing(char **argv, int *i)
{
	char	**splited;

	splited = parsing_utils(splited, argv, *i);
	*i = 0;
	while (splited[*i])
		(*i)++;
	checkduplicate(splited, *i);
	checkmaxint(splited, *i);
	return (splited);
}
