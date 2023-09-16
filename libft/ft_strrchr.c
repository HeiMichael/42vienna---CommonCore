/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:51:29 by miheider          #+#    #+#             */
/*   Updated: 2023/09/16 11:57:50 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	a;
	int	b;
	
	b = ft_strlen(s);
	a = (b - 1);
	while (a >= 0)
	{
		if (s[a] == c)
		{
			return ((char *)&s[a]);
		}
		a--;
	if (s[a] == (char *)c)
		return(char *)s + b);
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char str[] = "xwww.wassolldas.at";
	int c = 'x';

	printf("%s", ft_strrchr(str, c));
	return (0);
}*/
