/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:22:57 by aledru            #+#    #+#             */
/*   Updated: 2018/01/25 14:41:25 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw_fractal(t_fractol *fract)
{
	ft_bzero(fract->img->data, WIN_WIDTH * WIN_HEIGHT);
	if (ft_strcmp(fract->name, "mandelbrot") == 0)
		mandelbrot_draw(fract);
	if (ft_strcmp(fract->name, "julia") == 0)
		julia_draw(fract);
	display_image(fract);
}

t_fractol		*create_fractol(void *mlx, void *win, char *name, t_img *img)
{
	t_fractol	*fractol;

	if (!(fractol = (t_fractol*)ft_memalloc(sizeof(t_fractol))))
		malloc_error();
	fractol->mlx = mlx;
	fractol->win = win;
	fractol->img = img;
	fractol->name = name;
	fractol->max_iteration = 30;
	fractol->params = create_params(fractol);
	return (fractol);
}
