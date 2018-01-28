/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:14:01 by aledru            #+#    #+#             */
/*   Updated: 2018/01/28 20:43:43 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_iteration(int keycode, t_fractol *fract)
{
	if (keycode == KEY_PLUS)
		fract->max_iteration += 3;
	if (keycode == KEY_MINUS)
		if (fract->max_iteration > 10)
			fract->max_iteration -= 3;
	draw_fractal(fract);
}

void	translate(int keycode, t_fractol *fract)
{
	if (keycode == KEY_UP)
		fract->min->y -= 1 / fract->zoom * 10;
	if (keycode == KEY_DOWN)
		fract->min->y += 1 / fract->zoom * 10;
	if (keycode == KEY_LEFT)
		fract->min->x -= 1 / fract->zoom * 10;
	if (keycode == KEY_RIGHT)
		fract->min->x += 1 / fract->zoom * 10;
	printf("%f\n", fract->min->x);
	printf("%f\n", fract->min->y);
}

int		mlx_key_pressed(int keycode, t_fractol *fract)
{
	if (keycode == KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	if (keycode == KEY_R)
		reset_fractal(fract);
	if (keycode == KEY_M)
	{
		if (fract->mouse_disabled == 1)
			fract->mouse_disabled = 0;
		else
			fract->mouse_disabled = 1;
	}
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		change_iteration(keycode, fract);
	if (keycode == KEY_UP || keycode == KEY_DOWN ||
			keycode == KEY_LEFT || keycode == KEY_RIGHT)
		translate(keycode, fract);
	draw_fractal(fract);
	return (0);
}
