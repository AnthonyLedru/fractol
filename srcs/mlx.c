/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:26:08 by aledru            #+#    #+#             */
/*   Updated: 2018/01/19 14:18:46 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		display_image(t_fractol *fract)
{
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img->img_ptr, 0, 0);
	mlx_string_put(fract->mlx, fract->win, 10, 10, 0xFFFFFF, "Iteration: ");
	mlx_string_put(fract->mlx, fract->win, 120, 10, 0xFFFFFF,
			ft_itoa(fract->iteration));
}

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
	mlx_key_hook(win, mlx_key, fract);
	mlx_hook(win, 2, 0, mlx_key_pressed, fract);
	mlx_mouse_hook(win, mlx_zoom, fract);
	if (ft_strcmp(fractal_name, "mandelbrot") == 0)
		mandelbrot_setup_draw(fract);
	display_image(fract);
	mlx_loop(mlx);
}
