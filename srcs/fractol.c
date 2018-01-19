/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:22:57 by aledru            #+#    #+#             */
/*   Updated: 2018/01/19 15:20:30 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol		*create_fractol(void *mlx, void *win, char *name, t_img *img)
{
	t_fractol	*fractol;

	if (!(fractol = (t_fractol*)ft_memalloc(sizeof(t_fractol))))
		malloc_error();
	fractol->mlx = mlx;
	fractol->win = win;
	fractol->img = img;
	fractol->name = name;
	fractol->iteration = 30;
	fractol->mandelbrot = create_mandelbrot_params();
	return (fractol);
}
