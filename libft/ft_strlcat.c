/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:22:09 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/07 12:12:34 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	len;
	size_t	o;
	size_t	i;
	size_t	l;
	char	*a;

	a = (char *)src;
	i = 0;
	o = 0;
	len = ft_strlen(dst);
	o = ft_strlen(a);
	l = len;
	if (len > n)
		return (n + o);
	if (len == 0 && n == 0)
		return (l + o);
	while (a[i] != 0 && len < (n - 1))
	{
		dst[len] = a[i];
		i++;
		len++;
	}
	dst[len] = '\0';
	return (l + o);
}
