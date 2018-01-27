/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:18:20 by aledru            #+#    #+#             */
/*   Updated: 2018/01/27 19:40:00 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		julia_calc(t_complex *z, t_complex *c, double *i)
{
	double	tmp;

	tmp = z->r;
	set_complex(z, z->r * z->r - z->i * z->i + c->r,
				2 * z->i * tmp + c->i);
	*i = *i + 1.0;
}

static void		set_default_params(t_params *p, t_fract_thread *f_t)
{
	p->i = 0.0;
	set_complex(p->z, (p->p->x / f_t->fract->zoom) + f_t->fract->min->x,
					(p->p->y / f_t->fract->zoom) + f_t->fract->min->y);
}

static void			*julia_draw(void *fract_thread)
{
	t_fract_thread	*f_t;
	t_params		*p;

	f_t = (t_fract_thread*)fract_thread;
	p = f_t->thread->params;
	while (++p->p->x <= f_t->fract->thread_width + f_t->coord->x)
	{
		p->p->y = f_t->coord->y;
		while (++p->p->y <= f_t->fract->thread_height + f_t->coord->y)
		{
			set_default_params(p, f_t);
			while (sqrt(p->z->r * p->z->r + p->z->i *
							p->z->i) < 4 && p->i < f_t->fract->max_iteration)
				julia_calc(p->z, p->c, &(p->i));
			if (p->i == f_t->fract->max_iteration)
				put_pixel(p->p->x, p->p->y, f_t, 0);
			else
				put_pixel(p->p->x, p->p->y, f_t, p->i);
		}
	}
	free_fract_thread(fract_thread);
	pthread_exit(NULL);
}

void			julia_draw_setup(t_fractol *fract)
{
	int		th_id;
	t_point	*th;
	t_point	*p;

	th = create_point(-1, -1);
	p = create_point(-1, -1);
	th_id = -1;
	while (++th->x < sqrt(NB_THREAD))
	{
		p->x = -1;
		th->y = -1;
		while (++th->y < sqrt(NB_THREAD) && ++th_id >= 0)
		{
			set_point(fract->threads[th_id]->params->p, p->x, p->y);
			pthread_create(&(fract->threads[th_id]->th), NULL, julia_draw,
								create_fract_thread(fract->threads[th_id],
										fract, p->x, p->y));
			p->x += fract->thread_width;
		}
		p->y += fract->thread_height;
	}
	while (--th_id >= 0)
		pthread_join(fract->threads[th_id]->th, NULL);
	ft_memdel((void*)&th);
	ft_memdel((void*)&p);
}
