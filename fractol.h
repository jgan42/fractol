/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 10:47:19 by jgan              #+#    #+#             */
/*   Updated: 2016/01/03 10:47:24 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "X.h"
# define WIN_H 720
# define WIN_W WIN_H * 16 / 9
# include <stdio.h>

typedef struct	s_cplx
{
	double	x;
	double	y;
}				t_cplx;
typedef struct	s_pt
{
	int	x;
	int	y;
}				t_pt;
typedef struct	s_imgtmp
{
	t_cplx			z;
	int				i;
}				t_it;
typedef struct	s_fractol
{
	void	*mlx;
	void	*win;

	void	*im;
	char	*imc;
	int		bpp;
	int		imlen;
	int		endi;

	t_cplx	mid;
	t_cplx	def_min;
	t_cplx	def_max;
	t_cplx	curs;
	t_cplx	j_param;
	double	zoom;
	double	step;
	t_it	**it;
	t_it	**ib;
	char	type;
	int		i_min;
	int		i_max;
	int		b_max;
	int		b_max1;
	int		b_max2;
	int		power;

	char	ud;
	char	lr;
	char	zoom_io;
	char	color;
	char	j_mod;
	char	i_mod;

	t_pt	norm;
	int		hit;
}				t_fol;
typedef enum	e_key
{
	LEFT = 123,
	RIGHT = 124,
	DOWN = 125,
	UP = 126,
	NUM_0 = 82,
	NUM_2 = 84,
	NUM_4 = 86,
	NUM_6 = 88,
	NUM_8 = 91,
	PLUS = 69,
	MINUS = 78,
	MULT = 67,
	DIV = 75,
	ENTER = 76,
	ESC = 53,
	TAB = 48,
	SPACE = 49,
	ONE = 18,
	TWO = 19,
	THREE = 20,
	FOUR = 21,
	C = 8,
	V = 9,
	O = 31,
	P = 35,
}				t_key;

void			print_rules(t_fol *f);
int				init_fractol(t_fol *f);
int				init_it(t_fol *f);
int				init_ib(t_fol *f);
void			do_mlx(t_fol *f);
t_pt			to_matrix(t_fol *f, t_cplx t);
void			put_pixel(t_fol *f, t_pt i, int color);

void			mandelbrot(t_fol *f);
void			julia(t_fol *f);
void			buddha(t_fol *f);
void			buddha2(t_fol *f);

t_cplx			pow_c(t_cplx z, int p);
t_cplx			sum_c(t_cplx z1, t_cplx z2);
double			mod2_c(t_cplx z);

void			do_key(t_fol *f);
int				key_press(int key, t_fol *f);
int				key_release(int key, t_fol *f);

int				out_limits(t_fol *f);
#endif
