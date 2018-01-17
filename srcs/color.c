/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 13:49:20 by aledru            #+#    #+#             */
/*   Updated: 2018/01/17 17:08:33 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	*create_color_rgb(int r, int g, int b)
{
	t_color	*color;

	if (!(color = (t_color*)ft_memalloc(sizeof(t_color))))
		malloc_error();
	color->r = r;
	color->g = g;
	color->b = b;
	color->decimal = (r << 16) + (g << 8) + b;
	return (color);
}

t_color	*create_color(int decimal)
{
	t_color	*color;

	if (!(color = (t_color*)ft_memalloc(sizeof(t_color))))
		malloc_error();
	color->decimal = decimal;
	color->r = (decimal >> 16) & 0xff;
	color->g = (decimal >> 8) & 0xff;
	color->b = decimal & 0xff;
	return (color);
}
