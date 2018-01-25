/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:00:05 by aledru            #+#    #+#             */
/*   Updated: 2018/01/26 00:09:00 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_params(t_params *params, t_fractol *fract)
{
	params->z = create_complex(0.0, 0.0);
	if (ft_strcmp(fract->name, "mandelbrot") == 0)
	{
		params->min = create_point_d(-2.1, -1.2);
		params->c = create_complex(0.0, 0.0);
		params->zoom = 250;
	}
	if (ft_strcmp(fract->name, "julia") == 0)
	{
		params->min = create_point_d(-1.7, -1.2);
		params->c = create_complex(-0.882, 0.243);
		params->zoom = 250;
	}
	if (ft_strcmp(fract->name, "buddhabrot") == 0)
	{
		params->min = create_point_d(-2.1, -1.2);
		params->c = create_complex(0.41, 0.36);
		params->zoom = 250;
	}
}

t_params	*create_params(t_fractol *fract)
{
	t_params *params;

	if (!(params = (t_params*)
						ft_memalloc(sizeof(t_params))))
		malloc_error();
	set_params(params, fract);
	return (params);
}
