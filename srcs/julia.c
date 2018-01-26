/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:18:20 by aledru            #+#    #+#             */
/*   Updated: 2018/01/26 18:48:54 by aledru           ###   ########.fr       */
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

void			*julia_draw2(void *fracto)
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
			set_complex(params->z, (params->p->x / fract->zoom) + fract->min->x,
							(params->p->y / fract->zoom) + fract->min->y);
			julia_calc(params->z, fract->c, &i);
			while (sqrt(params->z->r * params->z->r + params->z->i *
							params->z->i) < 4 && i < fract->max_iteration)
				julia_calc(params->z, fract->c, &i);
			if (i == fract->max_iteration)
				put_pixel(params->p->x, params->p->y, fract, 0);
			else
				put_pixel(params->p->x, params->p->y, fract, i);
		}
	}
	return (NULL);
}

void			julia_draw(t_fractol *fract)
{
	set_point(fract->t1->params->p, 0, 0);
	julia_draw2(fract);
}
