/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:18:49 by aledru            #+#    #+#             */
/*   Updated: 2018/01/19 13:35:11 by aledru           ###   ########.fr       */
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
		
		mandelbrot_draw(fract);
		display_image(fract);
	}
	return (0);
}

int	mlx_zoom(int button, int x, int y, void *param)
{
	(void)button;
	(void)y;
	(void)x;
	(void)param;
	return (0);
}
