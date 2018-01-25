/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:13:38 by aledru            #+#    #+#             */
/*   Updated: 2018/01/26 00:07:08 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mlx_zoom(int button, int x, int y, t_fractol *fract)
{
	t_params		*params;
	t_point_double	*tmp;

	params = fract->params;
	tmp = create_point_d(0.0, 0.0);
	if (button == MOUSE_UP || (button == MOUSE_DOWN && params->zoom >= 250))
	{
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

int		mlx_move(int x, int y, t_fractol *fract)
{
	t_params	*p;

	p = fract->params;
	if (ft_strcmp(fract->name, "julia") == 0 && p->mouse_disabled == 0)
	{
		if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
			return (0);
		p->c->r = (double)x * -0.002205;
		p->c->i = (double)y * 0.00081;
	}
	draw_fractal(fract);
	return (0);
}
