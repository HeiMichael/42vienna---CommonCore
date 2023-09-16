/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 08:29:48 by miheider          #+#    #+#             */
/*   Updated: 2023/09/15 10:22:55 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_translate(char *str, int num, int len_n)
{
	while (len_n >= 0)
	{
		str[len_n] = (num % 10) + 48;
		num /= 10;
		len_n--;
	}
	return (str);
}

static int	length(int n, int len_n)
{
	while (n >= 9)
	{
		n = n / 10;
		len_n++;
	}
	return (len_n);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		num;
	int		len_n;
	char	*str;

	if (n == -2147483648)
		return ("-2147483648");
	len_n = 0;
	if (n < 0)
	{
		n *= -1;
		len_n++;
		sign = 1;
	}
	num = n;
	len_n = length(num, len_n);
	str = (char *)malloc((sizeof(char) * len_n) + 1);
	if (!str)
		return (NULL);
	str[len_n + 1] = '\0';
	str = ft_translate(str, num, len_n);
	if (sign == 1)
		str[0] = '-';
	return (str);
}

/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int	main(void)
{
	int	a;

	a = -2147483647;
	printf("%s", ft_itoa(a));
	return (0);
}*/
