/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:46:26 by aledru            #+#    #+#             */
/*   Updated: 2018/01/17 17:08:29 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		mandelbrot_calc(t_complex *z, t_complex *c, int *i)
{
	double tmp;

	tmp = z->r;
	set_complex(z, z->r = z->r * z->r - z->i * z->i + c->r,
				z->i = 2 * z->i * tmp + c->i);
	(*i)++;
}

void			mandelbrot_draw(t_fractol *fract)
{
	t_complex		*c;
	t_complex		*z;
	t_point			*p;
	t_point_double	*zoom;
	int				i;

	zoom = create_point_d(WIN_WIDTH / (0.6 - -2.1), WIN_HEIGHT / (1.2 - -1.2));
	p = create_point(0, 0);
	c = create_complex(0.0, 0.0);
	z = create_complex(0.0, 0.0);
	while (++p->x < WIN_WIDTH)
	{
		p->y = 0;
		while (++p->y < WIN_HEIGHT)
		{
			i = 0;
			set_complex(c, p->x / zoom->x + -2.1, p->y / zoom->y + -1.2);
			set_complex(z, 0, 0);
			mandelbrot_calc(z, c, &i);
			while (z->r * z->r + z->i * z->i < 4 && i < fract->iteration)
				mandelbrot_calc(z, c, &i);
			if (i == fract->iteration)
				draw_pixel(p->x, p->y, fract, 0);
			else
				draw_pixel(p->x, p->y, fract, i);
		}
	}
}
