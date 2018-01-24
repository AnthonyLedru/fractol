/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:18:49 by aledru            #+#    #+#             */
/*   Updated: 2018/01/24 19:15:48 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_iteration(int keycode, t_fractol *fract)
{
	if (keycode == KEY_PLUS)
		fract->max_iteration += 1;
	if (keycode == KEY_MINUS)
		if (fract->max_iteration > 10)
			fract->max_iteration -= 1;
	draw_fractal(fract);
}

void	translate(int keycode, t_fractol *fract)
{
	if (keycode == KEY_UP)
		fract->params->min->y -= 1 / fract->params->zoom * 10;
	if (keycode == KEY_DOWN)
		fract->params->min->y += 1 / fract->params->zoom * 10;
	if (keycode == KEY_LEFT)
		fract->params->min->x -= 1 / fract->params->zoom * 10;
	if (keycode == KEY_RIGHT)
		fract->params->min->x += 1 / fract->params->zoom * 10;
}

int		mlx_key_pressed(int keycode, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol*)param;
	if (keycode == KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	if(keycode == KEY_R)
		reset_params(fract->params);
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		change_iteration(keycode, fract);
	if (keycode == KEY_UP || keycode == KEY_DOWN ||
			keycode == KEY_LEFT || keycode == KEY_RIGHT)
		translate(keycode, fract);
	draw_fractal(fract);
	return (0);
}

int		mlx_zoom(int button, int x, int y, void *param)
{
	t_fractol		*fract;
	t_params		*params;
	t_point_double	*tmp;

	fract = (t_fractol*)param;
	params = fract->params;
	tmp = create_point_d(0.0, 0.0);
	if (button == MOUSE_UP || (button == MOUSE_DOWN && params->zoom >= 250))
	{
		ft_bzero(fract->img->data, WIN_WIDTH * WIN_HEIGHT);
		display_image(fract);
		set_point_d(tmp, x / params->zoom + params->min->x,
							y / params->zoom + params->min->y);
		if (button == MOUSE_DOWN)
		{
			params->zoom *= 0.5;
			mlx_key_pressed(KEY_MINUS, fract);
		}
		if (button == MOUSE_UP)
		{
			params->zoom *= 1.5;
			mlx_key_pressed(KEY_PLUS, fract);
		}
		params->min->x = tmp->x - (WIN_WIDTH / params->zoom) / 2;
		params->min->y = tmp->y - (WIN_HEIGHT / params->zoom) / 2;
		draw_fractal(fract);
	}
	return (0);
}
