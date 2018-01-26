/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:26:08 by aledru            #+#    #+#             */
/*   Updated: 2018/01/26 17:07:10 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		create_window(char *fractal_name)
{
	t_fractol	*fract;
	void		*mlx;
	void		*win;

	if (!(mlx = mlx_init()))
		exit(EXIT_FAILURE);
	if (!(win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, fractal_name)))
		exit(EXIT_FAILURE);
	fract = create_fractol(mlx, win, fractal_name,
			create_img(mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT)));
	mlx_hook(win, 2, (1L << 0), mlx_key_pressed, fract);
	mlx_hook(win, 6, (1L << 6), mlx_move, fract);
	mlx_mouse_hook(win, mlx_zoom, fract);
	draw_fractal(fract);
	mlx_loop(mlx);
}
