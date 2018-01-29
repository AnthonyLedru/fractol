/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:16:11 by aledru            #+#    #+#             */
/*   Updated: 2018/01/29 14:53:54 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <pthread.h>

# define WIN_HEIGHT		600
# define WIN_WIDTH		800
# define NB_THREAD		100

# define KEY_R			15
# define KEY_1			18
# define KEY_2			19
# define KEY_3			20
# define KEY_4			21
# define KEY_5			23
# define KEY_6			22
# define KEY_7			26
# define KEY_M			46
# define KEY_ESCAPE		53
# define KEY_PLUS		69
# define KEY_MINUS		78
# define KEY_LEFT		123
# define KEY_UP			126
# define KEY_RIGHT		124
# define KEY_DOWN		125

# define MOUSE_LEFT		1
# define MOUSE_RIGHT	2
# define MOUSE_DOWN		5
# define MOUSE_UP		4

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

typedef struct	s_params
{
	struct s_complex		*z;
	struct s_complex		*c;
	t_point					*p;
	double					i;
}				t_params;

typedef struct	s_thread_p
{
	pthread_t				th;
	int						id;
	struct	s_params		*params;
}				t_thread_p;

typedef struct	s_fractol
{
	void					*mlx;
	void					*win;
	struct s_img			*img;
	int						max_iteration;
	char					*name;
	int						mouse_disabled;
	double					zoom;
	struct s_point_double	*min;
	struct s_thread_p		*threads[NB_THREAD];
	int						thread_width;
	int						thread_height;
	int						selected_color;
}				t_fractol;

typedef struct	s_fract_thread
{
	struct s_fractol		*fract;
	struct s_thread_p		*thread;
	t_point					*coord;
}				t_fract_thread;
/*
** -------------------------------- Fractol ------------------------------------
*/

t_fractol		*create_fractol(void *mlx, void *win, char *name, t_img *img);
void			draw_fractal(t_fractol *fract);
void			reset_fractal(t_fractol *fract);

/*
** ------------------------------ Thread params --------------------------------
*/

t_thread_p		*create_thread_p(int id, t_fractol *fract);
void			reset_threads_params(t_fractol *fract);

/*
** ------------------------------ Fract thread ---------------------------------
*/

t_fract_thread	*create_fract_thread(t_thread_p *thread, t_fractol *fract,
										int x, int y);
void			free_fract_thread(t_fract_thread *f_t);

/*
** -------------------------------- Params -------------------------------------
*/

t_params		*create_params(t_fractol *fract);

/*
** ------------------------------- Mandelbrot ----------------------------------
*/

void			mandelbrot_draw_setup(t_fractol *fract);

/*
** --------------------------------- Julia -------------------------------------
*/

void			julia_draw_setup(t_fractol *fract);

/*
** ------------------------------ BurningShip ----------------------------------
*/

void			burningship_draw_setup(t_fractol *fract);

/*
** -------------------------------- Point --------------------------------------
*/

t_point			*create_point(int x, int y);
t_point_double	*create_point_d(double x, double y);
t_point			*copy_point(t_point *point);
void			set_point(t_point *point, int x, int y);
void			set_point_d(t_point_double *point, double x, double y);

/*
** ------------------------------- Complex -------------------------------------
*/

t_complex		*create_complex(double r, double i);
void			set_complex(t_complex *complex, double r, double i);

/*
** --------------------------------- Img ---------------------------------------
*/

t_img			*create_img(void *img);
void			put_pixel(int x, int y, t_fract_thread *fract, double i);
void			display_image(t_fractol *fract);

/*
** -------------------------------- Color --------------------------------------
*/

t_color			*create_color_rgb(int r, int g, int b);
t_color			*create_color(int decimal);

/*
** --------------------------------- Mlx ---------------------------------------
*/

void			create_window(char *fractal_name);

/*
** ------------------------------ Event Key ------------------------------------
*/

int				mlx_key_pressed(int keycode, t_fractol *fract);

/*
** ----------------------------- Event Mouse -----------------------------------
*/

int				mlx_zoom(int button, int x, int y, t_fractol *fract);
int				mlx_move(int x, int y, t_fractol *fract);

/*
** -------------------------------- Error --------------------------------------
*/

void			malloc_error(void);
void			arg_error(void);
void			thread_error(char *error);

#endif
