/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:00:05 by aledru            #+#    #+#             */
/*   Updated: 2018/01/26 18:12:20 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_params(t_params *params)
{
	params->z = create_complex(0.0, 0.0);
	params->p = create_point(0, 0);
}

void		set_params_threads(t_fractol *fract)
{
	init_params(fract->t1->params);
	init_params(fract->t2->params);
	init_params(fract->t3->params);
	init_params(fract->t4->params);
}

t_params	*create_params(t_thread_p *thread)
{
	t_params *params;

	if (!(params = (t_params*)ft_memalloc(sizeof(t_params))))
		malloc_error();
	init_params(params);
	thread->params = params;
	return (params);
}
