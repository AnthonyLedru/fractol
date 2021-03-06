/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:13:38 by aledru            #+#    #+#             */
/*   Updated: 2018/01/29 01:39:46 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mlx_zoom(int button, int x, int y, t_fractol *fract)
{
	t_point_double	*tmp;

	if (button == MOUSE_UP || (button == MOUSE_DOWN && fract->zoom >= 250))
	{
		tmp = create_point_d(x / fract->zoom + fract->min->x,
							y / fract->zoom + fract->min->y);
		if (button == MOUSE_DOWN)
		{
			fract->zoom /= 1.1;
			mlx_key_pressed(KEY_MINUS, fract);
		}
		if (button == MOUSE_UP)
		{
			fract->zoom *= 1.1;
			mlx_key_pressed(KEY_PLUS, fract);
		}
		fract->min->x += tmp->x - (x / fract->zoom + fract->min->x);
		fract->min->y += tmp->y - (y / fract->zoom + fract->min->y);
		draw_fractal(fract);
		ft_memdel((void*)&tmp);
	}
	return (0);
}

int		mlx_move(int x, int y, t_fractol *fract)
{
	int	i;

	if (ft_strcmp(fract->name, "julia") == 0 && fract->mouse_disabled == 0)
	{
		if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
			return (0);
		i = -1;
		while (++i < NB_THREAD)
			set_complex(fract->threads[i]->params->c, (double)x * -0.002205,
			(double)y * 0.00081);
		draw_fractal(fract);
	}
	return (0);
}
