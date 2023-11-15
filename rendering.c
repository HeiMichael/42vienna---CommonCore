/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:13:29 by miheider          #+#    #+#             */
/*   Updated: 2023/11/15 14:18:38 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rescale_pixels(int re, int im, t_fractol *red_thread)
{
	


}




void pixels(t_fractol *red_thread)
{
	int re;
	int	im;

	im = 0;
	while (im <= HIGHT)
	{
		re = 0;
		while (re <= WIDTH)
		{
			mandelbrot (re, im, red_thread);
			re++;
		}
		im++;
	}
}
