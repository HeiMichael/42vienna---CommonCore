/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:36:41 by miheider          #+#    #+#             */
/*   Updated: 2023/09/23 09:59:34 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	length;
	size_t	a;
	size_t	b;

	if (*little == '\0')
		return ((char *)big);
	length = 0;
	while (little[length] != '\0')
		length++;
	a = 0;
	while ((a < len) && big[a])
	{
		if (big[a] == little[0])
		{
			b = 0;
			while ((b < length) && (big[a + b] == little[b]) && (a + b < len))
				b++;
			if (b == length)
				return ((char *)&big[a]);
		}
		a++;
	}
	return (NULL);
}
