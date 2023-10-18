/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:22:14 by vvilensk          #+#    #+#             */
/*   Updated: 2023/10/15 12:17:56 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

// assembly?
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *const			dest = dst;
	const char *const	source = src;
	size_t				it;

	if (dst == src)
		return (dst);
	it = 0;
	while (it < n)
	{
		*(dest + it) = *(source + it);
		it++;
	}
	return (dst);
}

// assembly?
void	ft_bzero(void *s, size_t n)
{
	unsigned char *const	ptr = (unsigned char *)s;

	while (n--)
		*(ptr + n) = 0;
}

// assembly?
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
