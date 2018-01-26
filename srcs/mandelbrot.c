/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:46:26 by aledru            #+#    #+#             */
/*   Updated: 2018/01/26 18:21:17 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		mandelbrot_calc(t_complex *z, t_complex *c, double *i)
{
	double	tmp;

	tmp = z->r;
	set_complex(z, z->r * z->r - z->i * z->i + c->r,
				2 * z->i * tmp + c->i);
	*i = *i + 1.0;
}


void			*mandelbrot_draw2(void *fracto)
{
	double		i;
	t_fractol	*fract;
	t_params	*params;

	fract = (t_fractol*)fracto;
	params = fract->t1->params;
	while (++params->p->x < WIN_WIDTH)
	{
		params->p->y = 0;
		while (++params->p->y < WIN_HEIGHT)
		{
			i = 0.0;
			set_complex(fract->c, (params->p->x / fract->zoom) + fract->min->x,
							(params->p->y / fract->zoom) + fract->min->y);
			set_complex(params->z, 0, 0);
			mandelbrot_calc(params->z, fract->c, &i);
			while (sqrt(params->z->r * params->z->r + params->z->i *
							params->z->i) < 4 && i < fract->max_iteration)
				mandelbrot_calc(params->z, fract->c, &i);
			if (i == fract->max_iteration)
				put_pixel(params->p->x, params->p->y, fract, 0);
			else
				put_pixel(params->p->x, params->p->y, fract, i);
		}
	}
	pthread_exit(NULL);
	return (NULL);
}


void			mandelbrot_draw(t_fractol *fract)
{
	//t_point		*p;

	set_point(fract->t1->params->p, 0, 0);
	pthread_create(&(fract->t1->th), NULL, mandelbrot_draw2, fract);
	//mandelbrot_draw2(fract);
	pthread_join(fract->t1->th, NULL);
}
