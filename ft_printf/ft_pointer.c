/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:01:57 by miheider          #+#    #+#             */
/*   Updated: 2023/09/27 12:49:29 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_translate(unsigned long long number, int length)
{
	char	str[16];
	int		temp;
	int		a;

	a = length;
	str[length] = '\0';
	while (length - 1 >= 0)
	{
		temp = number % 16;
		if (temp < 10)
			str[length - 1] = temp + 48;
		else
			str[length - 1] = temp + 87;
		number /= 16;
		length--;
	}
	length = 0;
	while (length < a)
	{
		write (1, &str[length], 1);
		length++;
	}
}

int	ft_pointer(void *number)
{
	int					length;
	int					length_number;
	unsigned long long	pointer;
	unsigned long long	pointer2;

	pointer = (unsigned long long)number;
	if (pointer == -pointer)
		pointer = pointer * (-1);
	if (number == &number)
		pointer = (unsigned long long)&number;
	if (pointer == 0)
		return (write(1, "(nil)", 5));
	pointer2 = pointer;
	write (1, "0x", 2);
	length = 3;
	while (pointer2 > 15)
	{
		pointer2 = pointer2 / 16;
		length++;
	}
	length_number = length;
	ft_translate(pointer, length - 2);
	return (length_number);
}
/*
int main(void)
{
	void *a;
	//char b = 'u';
	
	ft_pointer(&a);
}*/
