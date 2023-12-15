/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:42:32 by miheider          #+#    #+#             */
/*   Updated: 2023/12/07 13:11:55 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <complex.h>
#include <stdio.h>

int	get_number1(const char *nptr, int *i, t_fractol *red_thread)
{
	int		x;

	x = 0;
	if (*nptr < 48 || *nptr > 57)
	{
		free(red_thread->name);
		error_message(4);
	}
	while (*nptr != '\0' && (*nptr >= 48 && *nptr <= 57))
	{
		x = 10 * x + (*nptr - 48);
		nptr++;
		(*i)++;
	}
	return (x);
}

double	get_number2(const char *nptr, int *i, t_fractol *red_thread)
{
	double	y;
	double	j;

	j = 0.1;
	y = 0.0;
	if (*nptr < 48 || *nptr > 57)
	{
		free(red_thread->name);
		error_message(4);
	}
	while (*nptr && (*nptr >= 48 && *nptr <= 57))
	{
		y += ((*nptr) - 48) * j;
		j = j / 10;
		(*i)++;
		nptr++;
	}
	return (y);
}

double	ft_strdou(const char *nptr, t_fractol *red_thread)
{
	int		i;
	int		x;
	double	y;
	int		sign;

	sign = 1;
	i = 0;
	x = 0;
	y = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] != '\0' && nptr[i] == 45)
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] != '\0' && nptr[i] == 43)
		i++;
	x = get_number1(&nptr[i], &i, red_thread);
	if (nptr[i] == 46 || nptr[i] == 44)
	{
		i++;
		y = get_number2(&nptr[i], &i, red_thread);
	}
	return (sign * (x + y));
}

void	init_struct(t_fractol *red_thread)
{
	red_thread->zoom = 1;
	red_thread->iter_max = 160;
	red_thread->hor = 0;
	red_thread->ver = 0;
	red_thread->z_real = 0.0;
	red_thread->r_min = 0;
	red_thread->r_max = 0;
	red_thread->r_sh = 0;
	red_thread->g_min = 0;
	red_thread->g_max = 255;
	red_thread->g_sh = 25;
	red_thread->b_min = 0;
	red_thread->b_max = 0;
	red_thread->b_sh = 0;
	red_thread->rj_min = 50;
	red_thread->rj_max = 200;
	red_thread->rj_sh = 0.1;
	red_thread->gj_min = 0;
	red_thread->gj_max = 200;
	red_thread->gj_sh = 0.2;
	red_thread->bj_min = 0;
	red_thread->bj_max = 200;
	red_thread->bj_sh = 0.1;
}

int	main(int argc, char *argv[])
{
	t_fractol	red_thread;

	if (argc == 1)
		error_message(1);
	if (argc == 3 || argc > 4)
		error_message(3);
	init_struct(&red_thread);
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 6)))
	{
		red_thread.name = ft_strdup(argv[1]);
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			red_thread.julia_real = ft_strdou(argv[2], &red_thread);
			red_thread.julia_im = ft_strdou(argv[3], &red_thread);
		}
		init(&red_thread);
	}
	else
		error_message(2);
	pixels(&red_thread);
	events(&red_thread);
	return (0);
}
