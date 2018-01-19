/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:16:11 by aledru            #+#    #+#             */
/*   Updated: 2018/01/19 16:49:12 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>

# define WIN_HEIGHT	600
# define WIN_WIDTH	800
# define KEY_PLUS	69
# define KEY_MINUS	78
# define MOUSE_DOWN	5
# define MOUSE_UP	4

/*
** --------------------------------- Struct ------------------------------------
*/

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

typedef struct	s_point_double
{
	double			x;
	double			y;
}				t_point_double;

typedef struct	s_complex
{
	double			r;
	double			i;
}				t_complex;

typedef struct	s_color
{
	int decimal;
	int r;
	int g;
	int b;
}				t_color;

typedef	struct	s_mandelbrot_params
{
	struct s_point_double	*p1;
	struct s_point_double	*p2;
	struct s_point_double	*zoom;
}				t_mandelbrot_params;

typedef struct	s_fractol
{
	void						*mlx;
	void						*win;
	struct s_img				*img;
	int							iteration;
	char						*name;
	struct s_mandelbrot_params	*mandelbrot;
}				t_fractol;

/*
** -------------------------------- Fractol ------------------------------------
*/

t_fractol			*create_fractol(void *mlx, void *win, char *name,
		t_img *img);

/*
** ------------------------------ Mandelbrot -----------------------------------
*/

void				mandelbrot_setup_draw(t_fractol *fract);

/*
** --------------------------- Mandelbrot Params -------------------------------
*/

t_mandelbrot_params	*create_mandelbrot_params(void);
void				set_zoom(t_mandelbrot_params *mandelbrot);

/*
** -------------------------------- Point --------------------------------------
*/

t_point				*create_point(int x, int y);
t_point_double		*create_point_d(double x, double y);
t_point				*copy_point(t_point *point);
void				set_point(t_point *point, int x, int y);
void				set_point_d(t_point_double *point, double x, double y);

/*
** ------------------------------- Complex -------------------------------------
*/

t_complex			*create_complex(double r, double i);
void				set_complex(t_complex *complex, double r, double i);

/*
** --------------------------------- Draw --------------------------------------
*/

void				draw_pixel(int x, int y, t_fractol *fract, int i);

/*
** ---------------------------------- Img --------------------------------------
*/

t_img				*create_img(void *img);

/*
** --------------------------------- Color -------------------------------------
*/

t_color				*create_color_rgb(int r, int g, int b);
t_color				*create_color(int decimal);

/*
** ---------------------------------- Mlx --------------------------------------
*/

void				create_window(char *fractal_name);
void				display_image(t_fractol *fract);

/*
** --------------------------------- Event -------------------------------------
*/

int					mlx_key(int keycode, void *param);
int					mlx_zoom(int button, int x, int y, void *param);
int					mlx_key_pressed(int keycode, void *param);

/*
** --------------------------------- Error -------------------------------------
*/

void				malloc_error();
void				arg_error();
#endif
