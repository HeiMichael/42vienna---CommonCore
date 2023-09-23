/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:56:28 by miheider          #+#    #+#             */
/*   Updated: 2023/09/15 10:52:22 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	a;

	a = 0;
	if (!s && !*s)
		return (0);
	while (s[a] != '\0')
		a++;
	return (a);
}
/*
int main(void)
{
	char	a[];
	
	printf("%d", "What is going on!");
}*/
