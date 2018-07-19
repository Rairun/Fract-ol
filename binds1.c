/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binds1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:09:08 by psaprono          #+#    #+#             */
/*   Updated: 2018/05/02 16:09:14 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		set_coefs(t_wind *wind, double r, double g, double b)
{
	wind->coef.r = r;
	wind->coef.g = g;
	wind->coef.b = b;
	create_fract(wind, 400);
	mlx_put_image_to_window(wind->mlx, wind->wind, wind->img_p, 0, 0);
	return (1);
}

int		mouse_hook(int k, int x, int y, t_wind *wind)
{
	if (k == 4 || k == 5)
		return (zoom_pic(k, wind));
	x = 0;
	y = 0;
	return (1);
}

int		zoom_pic(int k, t_wind *wind)
{
	if (k == 5)
		wind->pos.z *= 1.1;
	else
		wind->pos.z /= 1.1;
	create_fract(wind, 400);
	mlx_put_image_to_window(wind->mlx, wind->wind, wind->img_p, 0, 0);
	return (1);
}

int		move_pic(int k, t_wind *wind)
{
	if (k == 0)
		wind->pos.x -= 0.1 / wind->pos.z;
	else if (k == 2)
		wind->pos.x += 0.1 / wind->pos.z;
	else if (k == 13)
		wind->pos.y -= 0.1 / wind->pos.z;
	else if (k == 1)
		wind->pos.y += 0.1 / wind->pos.z;
	create_fract(wind, 400);
	mlx_put_image_to_window(wind->mlx, wind->wind, wind->img_p, 0, 0);
	return (1);
}

int		to_start(t_wind *wind)
{
	if (wind->mark == 1)
		set_mandelbrot(wind);
	else if (wind->mark == 2)
		set_julia(wind);
	else if (wind->mark == 3)
		set_tricorn(wind);
	create_fract(wind, 400);
	mlx_put_image_to_window(wind->mlx, wind->wind, wind->img_p, 0, 0);
	return (1);
}
