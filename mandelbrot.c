/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 07:40:40 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/25 07:40:43 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*show_mandelbrot(void *wind)
{
	t_comp	p;
	t_comp	new;
	t_comp	old;
	t_iter	it;
	t_wind	*win;

	win = wind;
	it.y = win->pos.min - 1;
	while (++it.y < win->pos.min + HGT / 400)
	{
		it.x = -1;
		while (++it.x < WID)
		{
			p.r = (it.x - WID / 2) / (0.4 * win->pos.z * WID) + win->pos.x;
			p.i = (it.y - HGT / 2) / (0.4 * win->pos.z * HGT) + win->pos.y;
			set_zeros(&new.r, &new.i, &old.r, &old.i);
			it.n = -1;
			while (++it.n < win->pos.max && new.r * new.r + new.i * new.i < 4)
				set_compl(&old, &new, p, 0);
			set_color(win, it, new);
		}
	}
	return (NULL);
}

void	*show_julia(void *wind)
{
	t_comp	new;
	t_comp	old;
	t_iter	it;
	t_wind	*win;

	win = wind;
	it.y = win->pos.min - 1;
	while (++it.y < win->pos.min + HGT / 400)
	{
		it.x = -1;
		while (++it.x < WID)
		{
			new.r = (it.x - WID / 2) / (0.4 * win->pos.z * WID) + win->pos.x;
			new.i = (it.y - HGT / 2) / (0.4 * win->pos.z * HGT) + win->pos.y;
			it.n = -1;
			while (++it.n < win->pos.max && new.r * new.r + new.i * new.i < 4)
			{
				old.r = new.r;
				new.r = old.r * old.r - new.i * new.i + win->c.r;
				new.i = 2 * old.r * new.i + win->c.i;
			}
			set_color(win, it, new);
		}
	}
	return (NULL);
}

void	*show_tricorn(void *wind)
{
	t_comp	p;
	t_comp	new;
	t_comp	old;
	t_iter	it;
	t_wind	*win;

	win = wind;
	it.y = win->pos.min - 1;
	while (++it.y < win->pos.min + HGT / 400)
	{
		it.x = -1;
		while (++it.x < WID)
		{
			p.r = (it.x - WID / 2) / (0.4 * win->pos.z * WID) + win->pos.x;
			p.i = (it.y - HGT / 2) / (0.4 * win->pos.z * HGT) + win->pos.y;
			set_zeros(&new.r, &new.i, &old.r, &old.i);
			it.n = -1;
			while (++it.n < win->pos.max && new.r * new.r + new.i * new.i < 4)
				set_compl(&old, &new, p, 1);
			set_color(win, it, new);
		}
	}
	return (NULL);
}

void	set_color(t_wind *win, t_iter it, t_comp z)
{
	t_col	c;
	double	k;

	k = it.n + 1 - (log(2) / log(sqrt(z.r * z.r + z.i * z.i))) / log(2);
	c.r = (unsigned char)(sin(win->coef.r * k + 4) * 230 + 25);
	c.g = (unsigned char)(sin(win->coef.g * k + 2) * 200 + 55);
	c.b = (unsigned char)(sin(win->coef.b * k + 1) * 230 + 25);
	if (it.n < win->pos.max)
		put_pix_to_img(win, it.x, it.y, convert_to_dec(c));
	else
		put_pix_to_img(win, it.x, it.y, 0x000000);
}

void	put_pix_to_img(t_wind *w, int x, int y, int color)
{
	if (x >= 0 && x < w->wh[0] && y >= 0 && y < w->wh[1])
		*(int *)(w->img_s + ((x + y * w->wh[0]) * 4)) = color;
}
