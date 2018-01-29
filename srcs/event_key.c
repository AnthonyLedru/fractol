/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:14:01 by aledru            #+#    #+#             */
/*   Updated: 2018/01/29 18:24:40 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	change_iteration(int keycode, t_fractol *fract)
{
	if (keycode == KEY_PLUS)
		fract->max_iteration += 3;
	if (keycode == KEY_MINUS)
		if (fract->max_iteration > 10)
			fract->max_iteration -= 3;
	draw_fractal(fract);
}

static void	translate(int keycode, t_fractol *fract)
{
	if (keycode == KEY_UP)
		fract->min->y -= 1 / fract->zoom * 10;
	if (keycode == KEY_DOWN)
		fract->min->y += 1 / fract->zoom * 10;
	if (keycode == KEY_LEFT)
		fract->min->x -= 1 / fract->zoom * 10;
	if (keycode == KEY_RIGHT)
		fract->min->x += 1 / fract->zoom * 10;
}

static int	get_color_selected(int keycode, t_fractol *fract)
{
	if (keycode == KEY_1)
		return (1);
	if (keycode == KEY_2)
		return (2);
	if (keycode == KEY_3)
		return (3);
	if (keycode == KEY_4)
		return (4);
	if (keycode == KEY_5)
		return (5);
	if (keycode == KEY_6)
		return (6);
	if (keycode == KEY_7)
		return (7);
	return (fract->selected_color);
}

int			mlx_key_pressed(int keycode, t_fractol *fract)
{
	if (keycode == KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	fract->selected_color = get_color_selected(keycode, fract);
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
