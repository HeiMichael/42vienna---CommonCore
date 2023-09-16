/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:01:31 by miheider          #+#    #+#             */
/*   Updated: 2023/09/16 11:58:26 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	a;
	
	if (s == NULL)
		return (NULL);
	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] == c)
		{
			return ((char *)&s[a]);
		}
		a++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int main(void)
{
	char string[] = "www.wasgehtab.at";
	char c = '#';

	printf("%s", ft_strchr(string, c));
	return (0);
}*/
