/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:16:41 by miheider          #+#    #+#             */
/*   Updated: 2023/09/15 10:40:49 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < (unsigned int)n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i != n)
		return (s1[i] - s2[i]);

	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char	a[] = "Was geht mit dir?";
	char	b[] = "Was geht?";
	int		num;

	num = 343;

	printf("%d\n", ft_strncmp(a, b, num));
	printf("%d", strncmp(a, b, num));
	return (0);

}*/
