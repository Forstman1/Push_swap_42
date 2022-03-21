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
#include "checker.h"

int	testcase1(char *rules)
{
	int i;

	i = 0;
	while (rules[i])
	{
		if (rules[i] == 's' && rules[i + 1] == 'a' && rules[i + 2] == '\n')
		{
			printf("%s\n", rules);
			exit(0);
		}
		i++;
	}
	return (0);
}


int main(int argc, char *argv[])
{
	int		i;
	char	*str;
	char	*ptr;
	char	*rules;
	char	**splited;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			checkvalid(argv[i]);
			str = ft_strjoin(str, argv[i]);
			str = ft_strjoin(str, " ");
			i++;
		}
		splited = ft_split(str, ' ');
		while (1)
		{
			printf("ana hna\n");
			rules = get_next_line(0);
			
		}
	}
	else
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
}
