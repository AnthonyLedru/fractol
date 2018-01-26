/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:45:26 by aledru            #+#    #+#             */
/*   Updated: 2018/01/26 12:39:52 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_fractal_name(char *fractal_name)
{
	if (ft_strcmp(fractal_name, "julia") != 0 &&
		ft_strcmp(fractal_name, "mandelbrot") != 0 &&
		ft_strcmp(fractal_name, "burningship") != 0)
		arg_error();
}

int		main(int ac, char **av)
{
	if (ac != 2)
		arg_error();
	check_fractal_name(av[1]);
	create_window(av[1]);
	return (0);
}
