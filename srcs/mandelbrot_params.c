/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:00:55 by aledru            #+#    #+#             */
/*   Updated: 2018/01/19 18:28:31 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				set_zoom(t_mandelbrot_params *mdbrot)
{
	mdbrot->zoom = create_point_d(WIN_WIDTH / (mdbrot->p2->x - mdbrot->p1->x),
								WIN_HEIGHT / (mdbrot->p2->y - mdbrot->p1->y));
}

t_mandelbrot_params	*create_mandelbrot_params(void)
{
	t_mandelbrot_params *mdbrot;

	if (!(mdbrot = (t_mandelbrot_params*)
						ft_memalloc(sizeof(t_mandelbrot_params))))
		malloc_error();
	mdbrot->p1 = create_point_d(-2.1, -1.2);
	mdbrot->p2 = create_point_d(0.6, 1.2);
	set_zoom(mdbrot);
	return (mdbrot);
}
