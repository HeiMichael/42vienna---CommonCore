/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:14:21 by miheider          #+#    #+#             */
/*   Updated: 2024/09/02 11:06:28 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		a;
	char	*dupl;

	a = ft_strlen(s);
	dupl = ft_calloc(1, a + 1);
	if (dupl == NULL)
		return (NULL);
	i = 0;
	while (i < a)
	{
		dupl[i] = s[i];
		i++;
	}
	dupl[i] = '\0';
	return (dupl);
}

/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char source[] = "GeeksForGeeks";
    char* target = ft_strdup(source);
 
    printf("%s", target);
    return (0);
}*/
