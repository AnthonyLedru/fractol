/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:22:57 by aledru            #+#    #+#             */
/*   Updated: 2018/01/19 13:40:44 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol		*create_fractol(void *mlx, void *win, t_img *img)
{
	t_fractol	*fractol;

	if (!(fractol = (t_fractol*)ft_memalloc(sizeof(t_fractol))))
		malloc_error();
	fractol->mlx = mlx;
	fractol->win = win;
	fractol->img = img;
	fractol->iteration = 30;
	return (fractol);
}
