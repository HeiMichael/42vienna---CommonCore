/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:04:14 by miheider          #+#    #+#             */
/*   Updated: 2023/09/15 10:46:05 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	*b;

	b = (unsigned char *)s;
	x = 0;
	while (x < n)
	{
		b[x] = (unsigned char)c;
		x++;
	}
	return (s);
}
