/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:00:05 by aledru            #+#    #+#             */
/*   Updated: 2018/01/24 19:38:38 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		reset_params(t_params *params)
{
	params->min = create_point_d(-2.1, -1.2);
	params->z = create_complex(0.0, 0.0);
	params->c = create_complex(0.0, 0.0);
	params->zoom = 250;
}

t_params	*create_params(void)
{
	t_params *params;

	if (!(params = (t_params*)
						ft_memalloc(sizeof(t_params))))
		malloc_error();
	params->min = create_point_d(-2.1, -1.2);
	params->z = create_complex(0.0, 0.0);
	params->c = create_complex(0.0, 0.0);
	params->zoom = 250;
	return (params);
}
