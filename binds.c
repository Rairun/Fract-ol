/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:21:00 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/26 16:21:01 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_binds(t_wind *wind)
{
	mlx_hook(wind->wind, 6, 1L < 6, mouse_julia, wind);
	mlx_hook(wind->wind, 17, 1L << 17, exit_press, wind);
	mlx_mouse_hook(wind->wind, mouse_hook, wind);
	mlx_hook(wind->wind, 2, 5, choice, (void *)wind);
}

int		mouse_julia(int x, int y, t_wind *wind)
{
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
	if (wind->pos.isfade == 1)
	{
		wind->c.r = (x - 300) / 128.0;
		wind->c.i = (y - 300) / 128.0;
		create_fract(wind, 400);
		mlx_put_image_to_window(wind->mlx, wind->wind, wind->img_p, 0, 0);
	}
	return (1);
}

int		exit_press(void)
{
	exit(1);
	return (1);
}

int		choice(int k, t_wind *wind)
{
	if (k == 53)
		exit(1);
	else if (k == 0 || k == 1 || k == 2 || k == 13)
		return (move_pic(k, wind));
	else if (k == 49)
		return (to_start(wind));
	else if (k == 18 || k == 19 || k == 20 || k == 21)
		return (change_color(k, wind));
	else if (k == 3)
	{
		if (wind->pos.isfade == 0)
			wind->pos.isfade = 1;
		else
			wind->pos.isfade = 0;
	}
	return (1);
}

int		change_color(int k, t_wind *wind)
{
	if (k == 18)
		return (set_coefs(wind, 0.07, 0.01, 0.01));
	else if (k == 19)
		return (set_coefs(wind, 0.01, 0.07, 0.01));
	else if (k == 20)
		return (set_coefs(wind, 0.01, 0.01, 0.07));
	else if (k == 21)
		return (set_coefs(wind, 0.7, 0.7, 0.7));
	return (1);
}
