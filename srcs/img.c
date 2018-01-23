/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:27:32 by aledru            #+#    #+#             */
/*   Updated: 2018/01/23 18:13:26 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img	*create_img(void *img)
{
	t_img *s_img;

	if (!(s_img = (t_img*)ft_memalloc(sizeof(t_img))))
		malloc_error();
	s_img->img_ptr = img;
	s_img->data = (int *)mlx_get_data_addr(s_img->img_ptr, &s_img->bpp,
			&s_img->size_line, &s_img->endian);
	return (s_img);
}

void	put_pixel(int x, int y, t_fractol *fract, int i)
{
	t_color		*color;
	t_params	*p;

	p = fract->params;
	i = i - log(log(p->z->r * p->z->r + p->z->i * p->z->i)) / log(2);
	i = (((3 * 256) - 1) * i) / fract->max_iteration;
	//color = create_color_rgb(0, 0, i * 255 / fract->max_iteration);
	color = create_color(i);
	if (y * WIN_WIDTH + x <= WIN_WIDTH * WIN_HEIGHT && y * WIN_WIDTH + x >= 0)
		fract->img->data[y * WIN_WIDTH + x] = color->decimal;
	ft_memdel((void*)&color);
}

void	display_image(t_fractol *fract)
{
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img->img_ptr, 0, 0);
	mlx_string_put(fract->mlx, fract->win, 10, 10, 0xFFFFFF, "Max iteration: ");
	mlx_string_put(fract->mlx, fract->win, 160, 10, 0xFFFFFF,
			ft_itoa(fract->max_iteration));
}
