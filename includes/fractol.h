/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:16:11 by aledru            #+#    #+#             */
/*   Updated: 2018/01/23 17:48:10 by aledru           ###   ########.fr       */
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
# define KEY_ESCAPE	53
# define KEY_LEFT	123
# define KEY_UP		126
# define KEY_RIGHT	124
# define KEY_DOWN	125

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

typedef	struct	s_params
{
	struct s_point_double	*min;
	struct s_point_double	*max;
	struct s_complex		*z;
	struct s_complex		*c;
	double					zoom;
}				t_params;

typedef struct	s_fractol
{
	void						*mlx;
	void						*win;
	struct s_img				*img;
	int							max_iteration;
	char						*name;
	struct s_params				*params;
}				t_fractol;

/*
** -------------------------------- Fractol ------------------------------------
*/

t_fractol			*create_fractol(void *mlx, void *win, char *name,
		t_img *img);

/*
** ------------------------------ Mandelbrot -----------------------------------
*/

void				mandelbrot_draw(t_fractol *fract);
void				draw_fractal(t_fractol *fract);

/*
** --------------------------- Params -------------------------------
*/

t_params			*create_params(void);
void				set_zoom(t_params *params);

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
** ---------------------------------- Img --------------------------------------
*/

t_img				*create_img(void *img);
void				put_pixel(int x, int y, t_fractol *fract, int i);
void				display_image(t_fractol *fract);

/*
** --------------------------------- Color -------------------------------------
*/

t_color				*create_color_rgb(int r, int g, int b);
t_color				*create_color(int decimal);

/*
** ---------------------------------- Mlx --------------------------------------
*/

void				create_window(char *fractal_name);

/*
** --------------------------------- Event -------------------------------------
*/

int					mlx_zoom(int button, int x, int y, void *param);
int					mlx_key_pressed(int keycode, void *param);

/*
** --------------------------------- Error -------------------------------------
*/

void				malloc_error();
void				arg_error();
#endif
