/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:39:30 by miheider          #+#    #+#             */
/*   Updated: 2023/09/15 10:36:35 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (8);
	return (0);
}

/*
#include<ctype.h>
#include<stdio.h>
int main(void)
{
	char	b;

	b = '?';

	printf("%d", ft_isalnum(b));
	return (0);
	
}*/
