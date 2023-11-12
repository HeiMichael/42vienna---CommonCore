/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:11:19 by miheider          #+#    #+#             */
/*   Updated: 2023/10/18 20:37:50 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static void	ft_putstr_fd(char *s, int fd)
{
	size_t	a;

	a = 0;
	while (s[a])
		a++;
	write(fd, s, a);
}

static void	ft_putstr_no_nl_fd(char *s, int fd)
{
	size_t	a;

	a = 0;
	while (s[a] != '\n')
		a++;
	write(fd, s, a);
}

void	print_search_result(char *key, char *value)
{
	if (value == NULL)
	{
		ft_putstr_no_nl_fd(key, 1);
		write(1, ": Not found.\n", 13);
	}
	else
		ft_putstr_fd(value, 1);
}
