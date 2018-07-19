/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:13:19 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/21 16:59:46 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_col	get_color(char *str)
{
	int		tmp;
	t_col	res;

	res.r = 255;
	res.g = 255;
	res.b = 255;
	if ((ft_strstr(str, ",0x")) != NULL)
	{
		tmp = (size_t)ft_strchr_n(str, 'x') + 1;
		res = convert_to_color(ft_strsub(str, tmp, ft_strlen(str) - tmp));
	}
	return (res);
}

t_col	convert_to_color(char *str)
{
	int	i;
	int	res;
	int	len;

	i = 0;
	res = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (what_n(str[len - i - 1]) == -1)
			return (convert_to_rgb(16777215));
		res += what_n(str[len - i - 1]) * pow(16, i);
		i++;
	}
	return (convert_to_rgb(res));
}

int		what_n(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	else if (c >= 'A' && c <= 'F')
		return (c - 55);
	else if (c >= 'a' && c <= 'f')
		return (c - 87);
	return (-1);
}

t_col	convert_to_rgb(int rgb)
{
	t_col	color;

	color.b = rgb & 255;
	color.g = (rgb >> 8) & 255;
	color.r = (rgb >> 16) & 255;
	return (color);
}

int		convert_to_dec(t_col color)
{
	int	res;

	res = (color.r << 16) + (color.g << 8) + color.b;
	return (res);
}
