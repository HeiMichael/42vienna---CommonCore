/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:14:26 by miheider          #+#    #+#             */
/*   Updated: 2023/09/26 15:31:42 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printchar(char c)
{
	int		length;

	length = 0;
	length += write(1, &c, 1);
	return (length);
}

int	ft_integer(int n)
{
	int	length;

	length = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = (-1) * n;
		length += 1;
	}
	if (n < 10)
		length += ft_printchar(n + 48);
	else
	{
		length += ft_integer((n / 10));
		length += ft_printchar(((n % 10) + 48));
	}
	return (length);
}
