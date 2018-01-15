/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:16:11 by aledru            #+#    #+#             */
/*   Updated: 2018/01/15 18:20:16 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# define WIN_HEIGHT	600
# define WIN_WIDTH	800

/*
** --------------------------------- Struct ------------------------------------
*/

typedef struct	s_fractol
{
	void			*mlx;
	void			*win;
	struct s_img	*img;
}				t_fractol;

typedef struct	s_img
{
	void			*img_ptr;
	int				bpp;
	int				size_line;
	int				endian;
	int				*data;
}				t_img;

typedef struct	s_point
{
	int				x;
	int				y;
}				t_point;

/*
** --------------------------------- Fractol -----------------------------------
*/

t_fractol		*create_fractol(void);

/*
** -------------------------------- Point --------------------------------------
*/

t_point			*create_point(int x, int y);
t_point			*copy_point(t_point *point);
void			set_point(t_point *point, int x, int y);

/*
** ----------------------------------- Img -------------------------------------
*/

t_img			*create_img(void *img);

/*
** ----------------------------------- Mlx -------------------------------------
*/

void			create_window(char *fractal_name, t_fractol *fract);

/*
** ---------------------------------- Event ------------------------------------
*/

int				mlx_key(int keycode, void *param);
int				mlx_zoom(int button, int x, int y, void *param);
int				mlx_key_pressed(int keycode, void *param);

/*
** ---------------------------------- Error ------------------------------------
*/

void			malloc_error();
void			arg_error();
#endif
