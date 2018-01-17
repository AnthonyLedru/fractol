/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:17:50 by aledru            #+#    #+#             */
/*   Updated: 2018/01/17 17:05:39 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel(int x, int y, t_fractol *fract, int i)
{
	t_color		*color;

	color = create_color_rgb(0, 0, i*255/fract->iteration);
	if (y * WIN_WIDTH + x <= WIN_WIDTH * WIN_HEIGHT && y * WIN_WIDTH + x >= 0)
		fract->img->data[y * WIN_WIDTH + x] = color->decimal;
	ft_memdel((void*)&color);
}
