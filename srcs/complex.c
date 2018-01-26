/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:22:17 by aledru            #+#    #+#             */
/*   Updated: 2018/01/26 13:35:43 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	*create_complex(double r, double i)
{
	t_complex	*complex;

	if (!(complex = (t_complex*)ft_memalloc(sizeof(t_complex))))
		malloc_error();
	complex->r = r;
	complex->i = i;
	return (complex);
}

void		set_complex(t_complex *complex, double r, double i)
{
	complex->r = r;
	complex->i = i;
}
