/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:18:49 by aledru            #+#    #+#             */
/*   Updated: 2018/01/19 18:57:57 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mlx_key(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int	mlx_key_pressed(int keycode, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol*)param;
	if (keycode == KEY_PLUS)
		fract->iteration += 10;
	if (keycode == KEY_MINUS)
		if (fract->iteration > 10)
			fract->iteration -= 10;
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
	{
		ft_bzero(fract->img->data, WIN_WIDTH * WIN_HEIGHT);
		if (ft_strcmp(fract->name, "mandelbrot") == 0)
		{
			mandelbrot_setup_draw(fract);
			display_image(fract);
		}
	}
	return (0);
}

int	mlx_zoom(int button, int x, int y, void *param)
{
	t_fractol	*fract;
	fract = (t_fractol*)param;

	if (button == MOUSE_DOWN)
	{
		set_point_d(fract->mandelbrot->p1, (double)(x / 200.0), (double)(y / 150.0));
		printf("%f\n", fract->mandelbrot->p1->x);
		set_point_d(fract->mandelbrot->p2, (double)(x / 200.0), (double)(y / 150.0));
		//set_zoom(fract->mandelbrot);
	}
	if (button == MOUSE_UP)
	{
		set_point_d(fract->mandelbrot->p2, (double)((x + 1) / WIN_WIDTH * WIN_HEIGHT), (double)((y + 1) / WIN_HEIGHT* WIN_WIDTH));
		set_zoom(fract->mandelbrot);
	}
	if (button == MOUSE_DOWN || button == MOUSE_UP)
		ft_bzero(fract->img->data, WIN_WIDTH * WIN_HEIGHT);
	if (ft_strcmp(fract->name, "mandelbrot") == 0)
	{
		mandelbrot_setup_draw(fract);
		display_image(fract);
	}
	(void)button;
	(void)y;
	(void)x;
	return (0);
}
