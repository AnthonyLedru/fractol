/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:19:25 by aledru            #+#    #+#             */
/*   Updated: 2018/01/19 15:50:21 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point			*create_point(int x, int y)
{
	t_point	*point;

	if (!(point = (t_point*)ft_memalloc(sizeof(t_point))))
		malloc_error();
	point->x = x;
	point->y = y;
	return (point);
}

t_point_double	*create_point_d(double x, double y)
{
	t_point_double	*point;

	if (!(point = (t_point_double*)ft_memalloc(sizeof(t_point_double))))
		malloc_error();
	point->x = x;
	point->y = y;
	return (point);
}

t_point			*copy_point(t_point *point)
{
	t_point	*point_cpy;

	if (!(point_cpy = (t_point*)ft_memalloc(sizeof(t_point))))
		malloc_error();
	point_cpy->x = point->x;
	point_cpy->y = point->y;
	return (point_cpy);
}

void			set_point(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}

void			set_point_d(t_point_double *point, double x, double y)
{
	point->x = x;
	point->y = y;
}
