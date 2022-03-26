/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:48:42 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/14 17:52:36 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cpypast(int o, char *a, char **b, char c)
{
	int	p;
	int	i;
	int	t;
	int	j;

	j = 0;
	p = 0;
	t = 0;
	while (o-- > 0)
	{
		i = 0;
		while (a[p] != c && a[p++])
			i++;
		b[t++] = ft_substr(a, j, i);
		while (a[p] == c)
			p++;
		j = p;
	}
	free(a);
	b[t] = NULL;
}

static int	numdelim(char *a, char c)
{
	int	o;
	int	i;

	o = 0;
	i = 0;
	while (a[i++])
		if (a[i] == c && a[i + 1] != c)
			o++;
	return (o);
}

static char	**nullcase(char *a)
{
	char	**b;

	b = (char **)malloc(sizeof(char *) * 1);
	b[0] = NULL;
	if (a[0] != 0)
		b[0] = ft_strdup(a);
	else
		return (b);
	b[1] = NULL;
	return (b);
}

char	**ft_split(const char *s, char c)
{
	int		o;
	char	*a;
	char	**b;

	a = (char *)s;
	b = NULL;
	if (!s)
		return (NULL);
	if (c == 0)
		return (nullcase(a));
	a = ft_strtrim(s, &c);
	if (!a)
		return (NULL);
	o = numdelim(a, c);
	if (a[0] == 0)
	{
		b = (char **)malloc(sizeof(char *));
		b[0] = NULL;
		free(a);
		return (b);
	}
	b = (char **)malloc(sizeof(char *) * (++o + 1));
	b[o - 1] = NULL;
	cpypast(o, a, b, c);
	return (b);
}
