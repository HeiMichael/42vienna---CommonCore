/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:32:52 by miheider          #+#    #+#             */
/*   Updated: 2023/09/15 10:36:03 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	int		b;
	size_t	i;
	size_t	j;

	a = ft_strlen(dst);
	b = ft_strlen(src);
	if (a >= size || size == 0)
		return (b + size);
	j = a;
	i = 0;
	while (src[i] != '\0' && i < (size - a - 1))
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (a + b);
}
