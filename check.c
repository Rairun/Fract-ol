/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:50:55 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/24 19:50:57 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check_arg(char *str, int argc)
{
	if (argc != 2)
	{
		show_massage();
		return (0);
	}
	if (ft_strcmp(str, "Mandelbrot") != 0 && ft_strcmp(str, "Julia") != 0 &&
		ft_strcmp(str, "Tricorn") != 0)
	{
		show_massage();
		return (0);
	}
	if (ft_strcmp(str, "Mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(str, "Julia") == 0)
		return (2);
	else if (ft_strcmp(str, "Tricorn") == 0)
		return (3);
	return (0);
}

void	show_massage(void)
{
	ft_putendl("Usage : ./fractol fractal_name");
	ft_putendl("		  \"Mandelbrot\"");
	ft_putendl("		  \"Julia\"");
	ft_putendl("		  \"Tricorn\"");
}
