/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:00:05 by aledru            #+#    #+#             */
/*   Updated: 2018/01/26 21:58:56 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_params(t_params *params, t_fractol *fract)
{
	params->z = create_complex(0.0, 0.0);
	if (ft_strcmp(fract->name, "mandelbrot") == 0)
		params->c = create_complex(0.0, 0.0);
	params->p = create_point(0, 0);
}

void		set_params_threads(t_fractol *fract)
{
	init_params(fract->t1->params, fract);
	init_params(fract->t2->params, fract);
	init_params(fract->t3->params, fract);
	init_params(fract->t4->params, fract);
}

t_params	*create_params(t_thread_p *thread, t_fractol *fract)
{
	t_params *params;

	if (!(params = (t_params*)ft_memalloc(sizeof(t_params))))
		malloc_error();
	init_params(params, fract);
	thread->params = params;
	return (params);
}
