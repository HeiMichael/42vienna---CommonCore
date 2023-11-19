/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheme.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:10:40 by miheider          #+#    #+#             */
/*   Updated: 2023/11/19 15:53:14 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NORM
//NOT QUIT UNEXPECTEDLY
//NO LEAKS
++//MAKEFILE (-Werror -Wall -Wextra) no relink / $(NAME), all, clean, fclean, re / bonus for BONUS
//BONUS in different files
//libft->copy sources and makefile

// RENDERING:
++// - Julia-set			./julia "re" "im"
++// - Mandelbrot-set		./mandelbrot
++// - (e) zoom in/out => mouse wheel (almost infinetifly within the limits of comp) (mouse_event)
++// - (b) different Julis-sets by passing different parameters
// - (b) parameter on com-line to what type of fractal will be displayed in window
++//		-can handle more para to use them as rendering options
//		-no parameter -> show a list of available param and exits properly
++// - a few colors to show the depth

// GRAPHIC:
++// - image in a window
++// - management of window must remain smooth
++// - ESC must close the window and quit program clean (key_event)
++// - clicking 'x' close the window and quit clean (mouse_event)
// - use of images of the MiniLibX!

// BONUS:
// - one more different fractal
// - zoom follows the mouse position
// - add to zoom: moving the view by pressing the arrow keys
// - color range shifts


++//int offset = (y * line_length + x * (bits_per_pixel / 8)); using line-len set by mlx_get_data_addr

#include<mlx.h>

int main(void)
{
	void	*mlx_connection;			//ptr
	void	*mlx_window;
	t_data	image;

++//1. set up the MiniLibX:
++//	mlx_connection = mlx_init();
++//	if (NULL == mlx_connection)
++//		return (1);
++//	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "fractol")
++//	if (NULL == mlx_window);
++//		return (1);
++//	img.img = mlX_new_image(mlx_connection, WIDTH, HEIGHT);
++//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

//2. calculating the image:
	my_mlx_pixel_put();					//selbst schreiben (=schneller!!!)
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);	//push image to window

//3. events:
	mlx_loop(mlx_connection);			//endles loop - waits for an event (and calls its function)

++//	mlx_destroy_display(mlx_ptr);		//free the display before finish
++//	free(mlx_ptr);
}
