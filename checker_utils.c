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

#include "checker/checker.h"
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
