/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:00:05 by aledru            #+#    #+#             */
/*   Updated: 2018/01/27 19:16:31 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		reset_params(t_params *params, t_fractol *fract)
{
	set_complex(params->z, 0.0, 0.0);
	if (ft_strcmp(fract->name, "mandelbrot") == 0)
		set_complex(params->c, 0.0, 0.0);
	if (ft_strcmp(fract->name, "julia") == 0)
		set_complex(params->c, -0.882, 0.243);
	if (ft_strcmp(fract->name, "burningship") == 0)
		set_complex(params->c, 0.0, 0.0);
	set_point(params->p, 0, 0);
}

void		reset_threads_params(t_fractol *fract)
{
	int	i;

	i = -1;
	while (++i < NB_THREAD)
		reset_params(fract->threads[i]->params, fract);
}

t_params	*create_params(t_fractol *fract)
{
	t_params *params;

	if (!(params = (t_params*)ft_memalloc(sizeof(t_params))))
		malloc_error();
	params->z = create_complex(0.0, 0.0);
	if (ft_strcmp(fract->name, "mandelbrot") == 0)
		params->c = create_complex(0.0, 0.0);
	if (ft_strcmp(fract->name, "julia") == 0)
		params->c = create_complex(-0.882, 0.243);
	if (ft_strcmp(fract->name, "burningship") == 0)
		params->c = create_complex(0.0, 0.0);
	params->p = create_point(0, 0);
	return (params);
}
