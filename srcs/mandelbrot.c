/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:46:26 by aledru            #+#    #+#             */
/*   Updated: 2018/01/19 19:03:09 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		mandelbrot_calc(t_complex *z, t_complex *c, int *i)
{
	double tmp;

	tmp = z->r;
	set_complex(z, z->r * z->r - z->i * z->i + c->r,
				2 * z->i * tmp + c->i);
	(*i)++;
}

void			mandelbrot_draw(t_fractol *fract, t_complex *c, t_complex *z,
		t_point *p)
{
	int					i;
	t_mandelbrot_params	*mdbrot;

	mdbrot = fract->mandelbrot;
	while (++p->x < WIN_WIDTH)
	{
		p->y = 0;
		while (++p->y < WIN_HEIGHT)
		{
			i = 0;
			set_complex(c, p->x / fract->mandelbrot->zoom->x + mdbrot->p1->x,
							p->y / fract->mandelbrot->zoom->y + mdbrot->p1->y);
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

void		mandelbrot_setup_draw(t_fractol *fract)
{
	t_complex		*c;
	t_complex		*z;
	t_point			*p;

	c = create_complex(0.0, 0.0);
	z = create_complex(0.0, 0.0);
	p = create_point(0, 0);
	mandelbrot_draw(fract, c, z, p);
}
