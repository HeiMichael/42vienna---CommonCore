/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:42:32 by miheider          #+#    #+#             */
/*   Updated: 2023/11/16 16:46:35 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol	red_thread;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		red_thread->name = ft_strdup(argv[1]);
		init(&red_thread);
					// if true --> jump into programm;
					++// --> initialisieren (connectin, window)
					// --> berechnen
					// --> darstellen
					// --> events
	}
	else
					//ERROR-MESSAGE + EXIT

	//2. berechnen&ausgeben:
	if (argv[1] == mandelbrot)
		mandelbrot();
	else
		julia();

	//3. events:
	events(&red_thread);

}
