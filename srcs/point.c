/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:19:25 by aledru            #+#    #+#             */
/*   Updated: 2018/01/10 13:10:16 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point			*create_point(int x, int y)
{
	t_point	*point;

	if (!(point = (t_point*)ft_memalloc(sizeof(t_point))))
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
