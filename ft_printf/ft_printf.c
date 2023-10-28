/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:10:00 by miheider          #+#    #+#             */
/*   Updated: 2023/10/25 22:58:28 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_putchar(char string)
{
	write (1, &string, 1);
	return (1);
}

static int	ft_count_arguments(char string, va_list args)
{
	int		length;

	length = 0;
	if (string == 'c')
		length += ft_character(va_arg(args, int));
	else if (string == 's')
		length += ft_string(va_arg(args, const char *));
	else if (string == 'p')
		length += ft_pointer(va_arg(args, void *));
	else if (string == 'i' || string == 'd')
		length += ft_integer(va_arg(args, int));
	else if (string == 'u')
		length += ft_dec_hexa(va_arg(args, unsigned int), 'u');
	else if (string == 'x')
		length += ft_dec_hexa(va_arg(args, unsigned int), 'x');
	else if (string == 'X')
		length += ft_dec_hexa(va_arg(args, unsigned int), 'X');
	else if (string == '%')
		length += ft_percent();
	return (length);
}

static void	initialize(int *i, int	*length)
{
	*i = 0;
	*length = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;
	int		i;

	initialize(&i, &length);
	if (format == NULL)
		return (-1);
	va_start (args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			while (format[i + 1] == ' ')
				i++;
			if ((format[i]) == ' ')
				length += write (1, " ", 1);
			length += ft_count_arguments((format[i + 1]), args);
			i++;
		}
		else
			length += ft_putchar(format[i]);
		i++;
	}
	va_end (args);
	return (length);
}

#include<stdio.h>
int main(void)
{
//	printf("%");
	ft_printf("%");
	return (0);
}
