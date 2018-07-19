/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:47:40 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/24 19:47:44 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_wind	*wind;

	if ((wind = (t_wind *)ft_memalloc(sizeof(*wind))) == NULL)
		ft_putendl("Error");
	if ((wind->mark = check_arg(argv[1], argc)) != 0)
	{
		init_window(wind);
		init_binds(wind);
		create_fract(wind, 400);
		mlx_put_image_to_window(wind->mlx, wind->wind, wind->img_p, 0, 0);
		mlx_loop(wind->mlx);
	}
	return (0);
}

void	init_window(t_wind *w)
{
	int		a[3];

	a[0] = 32;
	w->mlx = mlx_init();
	w->wh[0] = 800;
	w->wh[1] = 800;
	if (w->mark == 1)
		w->wind = mlx_new_window(w->mlx, w->wh[0], w->wh[1], "Mandelbrot");
	else if (w->mark == 2)
		w->wind = mlx_new_window(w->mlx, w->wh[0], w->wh[1], "Julia");
	else if (w->mark == 3)
		w->wind = mlx_new_window(w->mlx, w->wh[0], w->wh[1], "Tricorn");
	w->img_p = mlx_new_image(w->mlx, w->wh[0], w->wh[1]);
	w->img_s = mlx_get_data_addr(w->img_p, &a[0], &a[1], &a[2]);
	if (w->mark == 1)
		set_mandelbrot(w);
	else if (w->mark == 2)
		set_julia(w);
	else if (w->mark == 3)
		set_tricorn(w);
}

void	create_fract(t_wind *wind, int n)
{
	pthread_t	t[n];
	t_wind		w[n];
	t_iter		it;

	it.i = 0;
	it.j = 0;
	while (it.i < HGT)
	{
		w[it.j] = *wind;
		w[it.j].pos.min = it.i;
		if (wind->mark == 1)
			pthread_create(&t[it.j], NULL, show_mandelbrot, &w[it.j]);
		else if (wind->mark == 2)
			pthread_create(&t[it.j], NULL, show_julia, &w[it.j]);
		else if (wind->mark == 3)
			pthread_create(&t[it.j], NULL, show_tricorn, &w[it.j]);
		it.i += HGT / n;
		it.j++;
	}
	while (--it.j >= 0)
		pthread_join(t[it.j], NULL);
}
