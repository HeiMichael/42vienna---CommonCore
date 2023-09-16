/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:51:31 by miheider          #+#    #+#             */
/*   Updated: 2023/09/16 16:21:53 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	(unsigned char *)ft_memset(s, '\0', n);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[] = "AT89 5525 2255 3545 7452";
	size_t n = 20;

	ft_bzero(s, n);
	return (0);
}*/
