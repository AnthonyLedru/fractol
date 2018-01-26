/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:46:26 by aledru            #+#    #+#             */
/*   Updated: 2018/01/26 22:19:47 by aledru           ###   ########.fr       */
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

void			*mandelbrot_draw(void *fract_thread)
{
	t_fract_thread	*f_t;
	t_params		*params;
	t_fractol		*fract;
	int				thread_x;

	f_t = (t_fract_thread*)fract_thread;
	fract = (t_fractol*)f_t->fract;
	params = f_t->thread->params;
	if (f_t->thread->id == 1)
		thread_x = 0;
	if (f_t->thread->id == 2)
		thread_x = 200;
	if (f_t->thread->id == 3)
		thread_x = 400;
	if (f_t->thread->id == 4)
		thread_x = 600;
	while (++params->p->x <= fract->width + thread_x)
	{
		params->p->y = 0;
		while (++params->p->y < fract->height)
		{
			params->i = 0.0;
			set_complex(params->c, (params->p->x / fract->zoom) + fract->min->x,
							(params->p->y / fract->zoom) + fract->min->y);
			set_complex(params->z, 0, 0);
			mandelbrot_calc(params->z, params->c, &(params->i));
			while (sqrt(params->z->r * params->z->r + params->z->i *
							params->z->i) < 4 && params->i < fract->max_iteration)
				mandelbrot_calc(params->z, params->c, &(params->i));
			if (params->i == fract->max_iteration)
				put_pixel(params->p->x, params->p->y, f_t, 0);
			else
				put_pixel(params->p->x, params->p->y, f_t, params->i);
		}
	}
	pthread_exit(NULL);
	return (NULL);
}

void			mandelbrot_draw_setup(t_fractol *fract)
{
	t_fract_thread		*fract_thread;
	t_fract_thread		*fract_thread2;
	t_fract_thread		*fract_thread3;
	t_fract_thread		*fract_thread4;

	set_point(fract->t1->params->p, 0, 0);
	fract_thread = create_fract_thread(fract->t1, fract);
	pthread_create(&(fract->t1->th), NULL, mandelbrot_draw, fract_thread);

	set_point(fract->t2->params->p, 200, 0);
	fract_thread2 = create_fract_thread(fract->t2, fract);
	pthread_create(&(fract->t2->th), NULL, mandelbrot_draw, fract_thread2);

	set_point(fract->t3->params->p, 400, 0);
	fract_thread3 = create_fract_thread(fract->t3, fract);
	pthread_create(&(fract->t3->th), NULL, mandelbrot_draw, fract_thread3);

	set_point(fract->t4->params->p, 600, 0);
	fract_thread4 = create_fract_thread(fract->t4, fract);
	pthread_create(&(fract->t4->th), NULL, mandelbrot_draw, fract_thread4);
	pthread_join(fract->t1->th, NULL);
	pthread_join(fract->t2->th, NULL);
	pthread_join(fract->t3->th, NULL);
	pthread_join(fract->t4->th, NULL);
}
