/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:56:03 by miheider          #+#    #+#             */
/*   Updated: 2023/12/07 13:47:34 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	change_color1(int keysym, t_fractol *red_thread)
{
	if (keysym == XK_q && red_thread->r_max <= 250)
		red_thread->r_max += 5;
	if (keysym == XK_w && red_thread->r_min <= 250)
		red_thread->r_min += 5;
	if (keysym == XK_e && red_thread->r_sh <= 250)
		red_thread->r_sh += 5;
	if (keysym == XK_r && red_thread->g_max <= 250)
		red_thread->g_max += 5;
	if (keysym == XK_t && red_thread->g_min <= 250)
		red_thread->g_min += 5;
	if (keysym == XK_z && red_thread->g_sh <= 250)
		red_thread->g_sh += 5;
	if (keysym == XK_u && red_thread->b_max <= 250)
		red_thread->b_max += 5;
	if (keysym == XK_i && red_thread->b_min <= 250)
		red_thread->b_min += 5;
	if (keysym == XK_o && red_thread->b_sh <= 250)
		red_thread->b_sh += 5;
	return (0);
}

int	change_color2(int keysym, t_fractol *red_thread)
{
	if (keysym == XK_y && red_thread->r_max >= 5)
		red_thread->r_max -= 5;
	if (keysym == XK_x && red_thread->r_min >= 5)
		red_thread->r_min -= 5;
	if (keysym == XK_c && red_thread->r_sh >= 5)
		red_thread->r_sh -= 5;
	if (keysym == XK_v && red_thread->g_max >= 5)
		red_thread->g_max -= 5;
	if (keysym == XK_b && red_thread->g_min >= 5)
		red_thread->g_min -= 5;
	if (keysym == XK_n && red_thread->g_sh >= 5)
		red_thread->g_sh -= 5;
	if (keysym == XK_m && red_thread->b_max >= 5)
		red_thread->b_max -= 5;
	if (keysym == XK_comma && red_thread->b_min >= 5)
		red_thread->b_min -= 5;
	if (keysym == XK_period && red_thread->b_sh >= 5)
		red_thread->b_sh -= 5;
	return (0);
}

int	arrow(int keysym, t_fractol *red_thread)
{
	if (!ft_strncmp(red_thread->name, "burning_ship", 12))
	{
		if (keysym == XK_Down)
			red_thread->ver += 0.15 / red_thread->zoom;
		if (keysym == XK_Up)
			red_thread->ver -= 0.15 / red_thread->zoom;
		if (keysym == XK_Left)
			red_thread->hor -= 0.15 / red_thread->zoom;
		if (keysym == XK_Right)
			red_thread->hor += 0.15 / red_thread->zoom;
	}
	else
	{
		if (keysym == XK_Up)
			red_thread->ver += 0.15 / red_thread->zoom;
		if (keysym == XK_Down)
			red_thread->ver -= 0.15 / red_thread->zoom;
		if (keysym == XK_Left)
			red_thread->hor -= 0.15 / red_thread->zoom;
		if (keysym == XK_Right)
			red_thread->hor += 0.15 / red_thread->zoom;
	}
	return (0);
}

int	resolution(int keysym, t_fractol *red_thread)
{
	if (keysym == XK_p && red_thread->iter_max > 1
		&& red_thread->iter_max < 2500)
		red_thread->iter_max *= 1.2;
	if (keysym == XK_l && red_thread->iter_max > 1
		&& red_thread->iter_max < 2500)
		red_thread->iter_max /= 1.2;
	return (0);
}
