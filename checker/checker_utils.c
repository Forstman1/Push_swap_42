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


#include "checker.h"

char	*readline(char *s, char *buf, char *stati)
{
	int		i;
	void	*ptr;

	while (s == NULL || !ft_strchr(s, '\n'))
	{
		i = read(0, buf, 1);
		if (i <= 0)
		{
			if (stati && *stati)
				free(stati);
			if (s && *s)
				return (free(buf), s);
			return (free(buf), free(s), NULL);
		}
		ptr = s;
		s = ft_strjoin(s, buf);
		printf("%s", buf);
		free(ptr);
		ft_bzero(buf, 1 + 1);
	}
	return (free(buf), s);
}

/*******************/

char	*get_next_line(int fd)
{
	char		*s;
	char		*buf;
	static char	*stati;

	s = NULL;
	if (stati != NULL)
	{
		s = ft_strdup(stati);
		free(stati);
		stati = NULL;
	}
	buf = (char *)ft_calloc(1 + 1, sizeof(char));
	s = readline(s, buf, stati);
	if (s == NULL)
		return (NULL);
	if (ft_strchr(s, '\n'))
	{
		stati = ft_strdup(ft_strchr(s, '\n') + 1);
		ft_bzero(ft_strchr(s, '\n') + 1, ft_strlen(ft_strchr(s, '\n') + 1));
	}
	return (s);
}