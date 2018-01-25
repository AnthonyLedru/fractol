/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:03:19 by aledru            #+#    #+#             */
/*   Updated: 2018/01/25 15:07:42 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(void)
{
	ft_putstr_fd("error: Malloc failed\n", 2);
	exit(EXIT_FAILURE);
}

void	arg_error(void)
{
	ft_putstr_fd("Usage: <name> [mandelbrot/julia/other]\n", 2);
	exit(EXIT_FAILURE);
}
