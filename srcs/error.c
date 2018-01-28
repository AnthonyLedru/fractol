/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:03:19 by aledru            #+#    #+#             */
/*   Updated: 2018/01/27 20:22:38 by aledru           ###   ########.fr       */
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
	ft_putstr_fd("Usage: <name> [mandelbrot/julia/burningship]\n", 2);
	exit(EXIT_FAILURE);
}

void	thread_error(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}
