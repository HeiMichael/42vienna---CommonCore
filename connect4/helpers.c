/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:31:08 by mhuszar           #+#    #+#             */
/*   Updated: 2023/12/10 22:04:05 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	counter;

	counter = 0;
	while (s[counter])
	{
		write(fd, &s[counter], 1);
		counter++;
	}
}

int error_msg(char **grid, int y)
{
	int counter = 0;

	if (grid)
	{
		while(counter < y)
		{
			if (grid[counter])
				free(grid[counter]);
			counter++;
		}
		free(grid);
	}
	ft_putstr_fd("Error\n\n", 2);
	return (-1);
}

static int	survey(const char *str)
{
	int	c;
	int	minus_ctr;

	c = 0;
	minus_ctr = 0;
	while ((str[c] > 8 && str[c] < 14) || str[c] == 32)
		c++;
	if (str[c] == 43 || str[c] == 45)
	{
		if (str[c] == 45)
			minus_ctr++;
		c++;
	}
	if (minus_ctr % 2 == 0)
		return (c);
	else
		return (c * -1);
}

long int ft_atoi(const char *str)
{
	long int nb;
	int	sign;
	int	start;

	nb = 0;
	if (str[0] >= 'A' && str[0] <= 'Z')
	{
		if (str[1] == '\n')
			return (str[0] - 'A' + 10);
	}
	sign = survey(str);
	start = sign;
	if (sign < 0)
		start = sign * -1;
	while (str[start] > 47 && str[start] < 58)
	{
		nb = (nb * 10) + str[start] - '0';
		start++;
	}
	if (sign < 0)
		return (nb * -1);
	return (nb);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			ctr;
	unsigned char	*d;
	unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	ctr = 0;
	while (ctr < n)
	{
		*d = *s;
		ctr++;
		s++;
		d++;
	}
	return (d - n);
}

int	*top_list(char **grid, int x, int y)
{
	int *arr = ft_calloc(sizeof(int), x);
	if (!arr)
		return (NULL);
	int counter = 0;
	int last = y - 1;
	
	while (counter < x)
	{
		while (grid[last][counter] != 'F')
		{
			last--;
			if (last < 0)
				break ;
		}
        arr[counter] = last;
		last = y - 1;
        counter++;
	}
	return (arr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*x;

	x = (unsigned char *)s;
	while (n > 0)
	{
		*x++ = '\0';
		n--;
	}
}

/*
int *column_tops = top_list(grid, x, y);
grid[column_tops[5]][5];

grid[y][x];*/







