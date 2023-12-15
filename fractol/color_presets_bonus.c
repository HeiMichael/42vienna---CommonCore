/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_presets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:50:01 by miheider          #+#    #+#             */
/*   Updated: 2023/12/03 14:33:54 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	color_preset1(int keysym, t_fractol *red_thread)
{
	if (keysym == XK_a)
	{
		red_thread->r_max = 255;
		red_thread->r_sh = 15;
		red_thread->r_min = 0;
		red_thread->g_max = 0;
		red_thread->g_sh = 0;
		red_thread->g_min = 0;
		red_thread->b_max = 0;
		red_thread->b_sh = 0;
		red_thread->b_min = 0;
	}
	if (keysym == XK_s)
	{
		red_thread->r_max = 0;
		red_thread->r_sh = 0;
		red_thread->r_min = 0;
		red_thread->g_max = 0;
		red_thread->g_sh = 0;
		red_thread->g_min = 0;
		red_thread->b_max = 255;
		red_thread->b_sh = 15;
		red_thread->b_min = 0;
	}
	return (0);
}

int	color_preset2(int keysym, t_fractol *red_thread)
{
	if (keysym == XK_d)
	{
		red_thread->r_max = 0;
		red_thread->r_sh = 0;
		red_thread->r_min = 0;
		red_thread->g_max = 255;
		red_thread->g_sh = 15;
		red_thread->g_min = 0;
		red_thread->b_max = 0;
		red_thread->b_sh = 0;
		red_thread->b_min = 0;
	}
	if (keysym == XK_f)
	{
		red_thread->r_max = 255;
		red_thread->r_sh = 15;
		red_thread->r_min = 20;
		red_thread->g_max = 255;
		red_thread->g_sh = 15;
		red_thread->g_min = 20;
		red_thread->b_max = 255;
		red_thread->b_sh = 15;
		red_thread->b_min = 20;
	}
	return (0);
}

int	color_preset3(int keysym, t_fractol *red_thread)
{
	if (keysym == XK_g)
	{
		red_thread->r_max = 255;
		red_thread->r_sh = 15;
		red_thread->r_min = 0;
		red_thread->g_max = 255;
		red_thread->g_sh = 15;
		red_thread->g_min = 0;
		red_thread->b_max = 0;
		red_thread->b_sh = 0;
		red_thread->b_min = 0;
	}
	if (keysym == XK_h)
	{
		red_thread->r_max = 255;
		red_thread->r_sh = 5;
		red_thread->r_min = 0;
		red_thread->g_max = 0;
		red_thread->g_sh = 0;
		red_thread->g_min = 0;
		red_thread->b_max = 255;
		red_thread->b_sh = 5;
		red_thread->b_min = 0;
	}
	return (0);
}

int	color_preset4(int keysym, t_fractol *red_thread)
{
	if (keysym == XK_j)
	{
		red_thread->r_max = 0;
		red_thread->r_sh = 0;
		red_thread->r_min = 0;
		red_thread->g_max = 255;
		red_thread->g_sh = 15;
		red_thread->g_min = 0;
		red_thread->b_max = 255;
		red_thread->b_sh = 15;
		red_thread->b_min = 0;
	}
	if (keysym == XK_k)
	{
		red_thread->r_max = 102;
		red_thread->r_sh = 15;
		red_thread->r_min = 25;
		red_thread->g_max = 200;
		red_thread->g_sh = 5;
		red_thread->g_min = 0;
		red_thread->b_max = 123;
		red_thread->b_sh = 8;
		red_thread->b_min = 20;
	}
	return (0);
}
