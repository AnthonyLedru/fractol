/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:22:57 by aledru            #+#    #+#             */
/*   Updated: 2018/01/29 18:26:33 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fract_param(t_fractol *fract)
{
	fract->zoom = 250;
	fract->max_iteration = 50;
	if (ft_strcmp(fract->name, "mandelbrot") == 0)
		fract->min = create_point_d(-2.1, -1.2);
	if (ft_strcmp(fract->name, "julia") == 0)
		fract->min = create_point_d(-1.62, -1.2);
	if (ft_strcmp(fract->name, "burningship") == 0)
		fract->min = create_point_d(-2.02, -1.79);
}

void		reset_fractal(t_fractol *fract)
{
	reset_threads_params(fract);
	fract->zoom = 250;
	fract->max_iteration = 50;
	if (ft_strcmp(fract->name, "mandelbrot") == 0)
		set_point_d(fract->min, -2.1, -1.2);
	if (ft_strcmp(fract->name, "julia") == 0)
		set_point_d(fract->min, -1.62, -1.2);
	if (ft_strcmp(fract->name, "burningship") == 0)
		set_point_d(fract->min, -2.02, -1.79);
}

void		draw_fractal(t_fractol *fract)
{
	ft_bzero(fract->img->data, WIN_WIDTH * WIN_HEIGHT);
	if (ft_strcmp(fract->name, "mandelbrot") == 0)
		mandelbrot_draw_setup(fract);
	if (ft_strcmp(fract->name, "julia") == 0)
		julia_draw_setup(fract);
	if (ft_strcmp(fract->name, "burningship") == 0)
		burningship_draw_setup(fract);
	display_image(fract);
}

t_fractol	*create_fractol(void *mlx, void *win, char *name, t_img *img)
{
	t_fractol	*fract;
	int			i;

	if (!(fract = (t_fractol*)ft_memalloc(sizeof(t_fractol))))
		malloc_error();
	fract->mlx = mlx;
	fract->win = win;
	fract->img = img;
	fract->name = name;
	fract->mouse_disabled = 0;
	init_fract_param(fract);
	i = -1;
	while (++i < NB_THREAD)
		fract->threads[i] = create_thread_p(i, fract);
	fract->thread_width = WIN_WIDTH / sqrt(NB_THREAD);
	fract->thread_height = WIN_HEIGHT / sqrt(NB_THREAD);
	fract->selected_color = 1;
	return (fract);
}
