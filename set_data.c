/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 11:43:04 by psaprono          #+#    #+#             */
/*   Updated: 2018/05/03 11:43:06 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_mandelbrot(t_wind *wind)
{
	wind->pos.x = -0.7;
	wind->pos.y = 0.0;
	wind->pos.z = 1.0;
	wind->pos.max = 100;
	wind->coef.r = 0.04;
	wind->coef.g = 0.02;
	wind->coef.b = 0.03;
}

void	set_julia(t_wind *wind)
{
	wind->pos.x = 0.0;
	wind->pos.y = 0.0;
	wind->pos.z = 0.8;
	wind->pos.isfade = 1;
	wind->c.r = 10.0;
	wind->c.i = 10.0;
	wind->pos.max = 100;
	wind->coef.r = 0.04;
	wind->coef.g = 0.02;
	wind->coef.b = 0.03;
}

void	set_tricorn(t_wind *wind)
{
	wind->pos.x = -0.25;
	wind->pos.y = 0.0;
	wind->pos.z = 0.7;
	wind->pos.max = 100;
	wind->coef.r = 0.04;
	wind->coef.g = 0.02;
	wind->coef.b = 0.03;
}

void	set_zeros(double *a, double *b, double *c, double *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

void	set_compl(t_comp *old, t_comp *new, t_comp p, int k)
{
	if (k == 1)
		new->i *= -1;
	old->r = new->r;
	new->r = old->r * old->r - new->i * new->i + p.r;
	new->i = 2 * old->r * new->i + p.i;
}
