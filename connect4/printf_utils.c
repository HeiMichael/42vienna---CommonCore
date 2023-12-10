/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:05:16 by mhuszar           #+#    #+#             */
/*   Updated: 2023/09/25 17:05:18 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "connect4.h"

int	print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	digit_count(int y)
{
	int	counter;
	int	nb;

	counter = 1;
	if (y == -2147483648)
		return (11);
	else if (y < 0)
		nb = (y * -1);
	else
		nb = y;
	while (nb > 9)
	{
		nb = nb / 10;
		counter++;
	}
	if (y < 0)
		return (counter + 1);
	else
		return (counter);
}

static void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int	print_i(int i)
{
	ft_putnbr(i);
	return (digit_count(i));
}

static int	p_digit_count(unsigned long long int p)
{
	int	counter;

	counter = 1;
	while (p > 15)
	{
		p = p / 16;
		counter++;
	}
	return (counter);
}

static void	print_p_sub(unsigned long long int p)
{
	if (p > 15)
	{
		print_p_sub(p / 16);
		print_p_sub(p % 16);
	}
	else if (p < 10)
		ft_putchar(p + '0');
	else
		ft_putchar(p - 10 + 'a');
}

int	print_p(void *ptr)
{
	unsigned long long int	address;

	address = (unsigned long long int)ptr;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	print_p_sub(address);
	return (p_digit_count(address) + 2);
}

int	print_s(char *str)
{
	int	counter;

	counter = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[counter])
	{
		write(1, &str[counter], 1);
		counter++;
	}
	return (counter);
}

static int	digit_u(unsigned int y)
{
	int	counter;

	counter = 1;
	while (y > 9)
	{
		y = y / 10;
		counter++;
	}
	return (counter);
}

static void	put_u(unsigned int u)
{
	if (u > 9)
	{
		put_u(u / 10);
		put_u(u % 10);
	}
	else
		ft_putchar(u + '0');
}

int	print_u(unsigned int u)
{
	put_u(u);
	return (digit_u(u));
}

static int	x_digit_count(unsigned int x)
{
	int	counter;

	counter = 1;
	while (x > 15)
	{
		x = x / 16;
		counter++;
	}
	return (counter);
}

int	print_x(unsigned int x)
{
	if (x > 15)
	{
		print_x(x / 16);
		print_x(x % 16);
	}
	else if (x < 10)
		ft_putchar(x + '0');
	else
		ft_putchar(x - 10 + 'a');
	return (x_digit_count(x));
}

int	print_xup(unsigned int x)
{
	if (x > 35)
	{
		print_xup(x / 36);
		print_xup(x % 36);
	}
	else if (x < 10)
		ft_putchar(x + '0');
	else
		ft_putchar(x - 10 + 'A');
	return (x_digit_count(x));
}
