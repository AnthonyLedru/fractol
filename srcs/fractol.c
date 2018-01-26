/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:22:57 by aledru            #+#    #+#             */
/*   Updated: 2018/01/26 22:30:55 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		reset_fractal(t_fractol *fract)
{
	set_params_threads(fract);
	fract->zoom = 250;
	fract->max_iteration = 30;
	if (ft_strcmp(fract->name, "mandelbrot") == 0)
	{
		set_point_d(fract->min, -2.1, -1.2);
		//set_complex(fract->c, 0.0, 0.0);
	}
	if (ft_strcmp(fract->name, "julia") == 0)
	{
		set_point_d(fract->min, -1.7, -1.2);
		//set_complex(fract->c, -0.882, 0.243);
	}
	if (ft_strcmp(fract->name, "burningship") == 0)
	{
		set_point_d(fract->min, -2.02, -1.79);
		//set_complex(fract->c, 0.0, 0.0);
	}
}

void		draw_fractal(void *fractol)
{
	t_fractol *fract;

	fract = (t_fractol*)fractol;
	ft_bzero(fract->img->data, WIN_WIDTH * WIN_HEIGHT);
	if (ft_strcmp(fract->name, "mandelbrot") == 0)
		mandelbrot_draw_setup(fract);
	if (ft_strcmp(fract->name, "julia") == 0)
		julia_draw(fract);
	if (ft_strcmp(fract->name, "burningship") == 0)
		burningship_draw(fract);
	display_image(fract);
}

void		init_fract_param(t_fractol *fract)
{
	fract->zoom = 250;
	if (ft_strcmp(fract->name, "mandelbrot") == 0)
	{
		//fract->c = create_complex(0.0, 0.0);
		fract->min = create_point_d(-2.1, -1.2);
	}
	if (ft_strcmp(fract->name, "julia") == 0)
	{
		fract->min = create_point_d(-1.7, -1.2);
		//fract->c = create_complex(-0.882, 0.243);
	}
	if (ft_strcmp(fract->name, "burningship") == 0)
	{
		fract->min = create_point_d(-2.02, -1.79);
		//fract->c = create_complex(0.0, 0.0);
	}
}

t_fractol	*create_fractol(void *mlx, void *win, char *name, t_img *img)
{
	t_fractol	*fract;

	if (!(fract = (t_fractol*)ft_memalloc(sizeof(t_fractol))))
		malloc_error();
	fract->mlx = mlx;
	fract->win = win;
	fract->img = img;
	fract->max_iteration = 30;
	fract->name = name;
	fract->mouse_disabled = 0;
	init_fract_param(fract);
	fract->t1 = create_thread_p(1, fract);
	fract->t2 = create_thread_p(2, fract);
	fract->t3 = create_thread_p(3, fract);
	fract->t4 = create_thread_p(4, fract);
	fract->width = WIN_WIDTH / 4;
	fract->height = WIN_HEIGHT;
	return (fract);
}
