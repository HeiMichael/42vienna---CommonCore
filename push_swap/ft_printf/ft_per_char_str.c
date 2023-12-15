/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_per_char_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:50:52 by miheider          #+#    #+#             */
/*   Updated: 2023/09/29 14:54:22 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(void)
{
	write (1, "%", 1);
	return (1);
}

int	ft_character(int character)
{
	write (1, &character, 1);
	return (1);
}

int	ft_string(const char *string)
{
	int	i;

	if (!string)
		return (write(1, "(null)", 6));
	i = 0;
	while (string[i])
	{
		write (1, &string[i], 1);
		i++;
	}
	return (i);
}
