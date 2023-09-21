/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 08:29:48 by miheider          #+#    #+#             */
/*   Updated: 2023/09/16 18:43:06 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_translate(char *str, int num, int len_n, int sign)
{
	str[len_n] = '\0';
	while ((len_n) >= 1)
	{
		str[len_n - 1] = (num % 10) + '0';
		num /= 10;
		len_n--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

static int	length(int n, int len_n)
{
	while (n > 9)
	{
		n = n / 10;
		len_n++;
	}
	return (len_n);
}

static char	*check_intmin(int num)
{
	char	*str;

	if (num == -2147483648)
	{
		str = malloc(sizeof(char) * 12);
		if (NULL == str)
			return (0);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	return (0);
}

static void	signer(long long int *num, int n, int *sign)
{
	*num = n;
	*sign = 0;
}

char	*ft_itoa(int n)
{
	int				sign;
	long long int	num;
	int				len_n;
	char			*str;

	signer(&num, n, &sign);
	str = check_intmin(num);
	if (str != 0)
		return (str);
	len_n = 1;
	if (n < 0)
	{
		n *= -1;
		len_n = 2;
		sign = 1;
	}
	num = n;
	len_n = length(num, len_n);
	str = (char *)malloc(sizeof(char) * (len_n + 1));
	if (!str)
		return (NULL);
	str = ft_translate(str, num, len_n, sign);
	return (str);
}

/*
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int    a;

	a = 10;
	printf("%s", ft_itoa(a));
	return (0);
}*/
