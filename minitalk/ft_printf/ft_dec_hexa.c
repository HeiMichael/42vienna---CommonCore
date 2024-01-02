/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:14:26 by miheider          #+#    #+#             */
/*   Updated: 2023/09/29 14:50:29 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_diff(char c)
{
	int	diff;

	diff = 87;
	if (c == 'X')
		diff = 55;
	return (diff);
}

static void	ft_translate(unsigned int number, int length, char c, int divider)
{
	char	str[12];
	int		temp;
	int		a;
	int		diff;

	diff = ft_diff(c);
	a = length;
	str[length] = '\0';
	while (length - 1 >= 0)
	{
		temp = number % divider;
		if (temp < 10)
			str[length - 1] = temp + 48;
		else
			str[length - 1] = temp + diff;
		number /= divider;
		length--;
	}
	length = 0;
	while (length < a)
	{
		write (1, &str[length], 1);
		length++;
	}
}

int	ft_dec_hexa(unsigned int number, char c)
{
	int	length;
	int	length_number;
	int	num;
	int	divider;

	divider = 10;
	if (c == 'x' || c == 'X')
		divider = 16;
	if (number == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	num = number;
	length = 1;
	while (number > ((unsigned int)divider - 1))
	{
		number = number / divider;
		length++;
	}
	length_number = length;
	ft_translate(num, length, c, divider);
	return (length_number);
}
/*
int main(void)
{
	long long a = 96;
	char b = 'u';
}
	printf ("\n{%d}", ft_hexadec(a, b));
	return (0);
}*/
