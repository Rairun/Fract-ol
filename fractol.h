/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:58:30 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/24 19:58:34 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread.h>
# include <math.h>
# include "get_next_line.h"
# include "mlx.h"

# define WID 800
# define HGT 800

typedef struct	s_coef
{
	double		r;
	double		g;
	double		b;
}				t_coef;

typedef struct	s_iter
{
	int			y;
	int			x;
	int			n;
	int			i;
	int			j;
}				t_iter;

typedef struct	s_col
{
	int			r;
	int			g;
	int			b;
}				t_col;

typedef struct	s_pos
{
	double		z;
	double		x;
	double		y;
	int			min;
	int			max;
	int			isfade;
}				t_pos;

typedef struct	s_comp
{
	double		r;
	double		i;
}				t_comp;

typedef struct	s_wind
{
	void		*mlx;
	void		*wind;
	void		*img_p;
	char		*img_s;
	int			wh[2];
	t_comp		c;
	t_pos		pos;
	t_coef		coef;
	int			mark;
}				t_wind;

int				check_arg(char *str, int argc);
void			show_massage(void);
void			init_window(t_wind *w);
void			*show_mandelbrot(void *wind);
void			put_pix_to_img(t_wind *w, int x, int y, int color);
void			init_binds(t_wind *wind);
int				exit_press(void);
int				choice(int k, t_wind *wind);
int				mouse_hook(int k, int x, int y, t_wind *wind);
void			set_color(t_wind *win, t_iter it, t_comp z);
int				zoom_pic(int k, t_wind *wind);
void			create_fract(t_wind *wind, int n);
int				move_pic(int k, t_wind *wind);
int				to_start(t_wind *wind);
int				change_color(int k, t_wind *wind);
int				set_coefs(t_wind *wind, double r, double g, double b);
void			*show_julia(void *wind);
int				mouse_julia(int x, int y, t_wind *wind);
void			set_mandelbrot(t_wind *wind);
void			set_julia(t_wind *wind);
void			*show_tricorn(void *wind);
void			set_tricorn(t_wind *wind);
void			set_zeros(double *a, double *b, double *c, double *d);
void			set_compl(t_comp *old, t_comp *new, t_comp p, int k);
t_col			get_color(char *str);
t_col			convert_to_color(char *str);
int				what_n(char c);
t_col			convert_to_rgb(int rgb);
int				convert_to_dec(t_col color);

#endif
