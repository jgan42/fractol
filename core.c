/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 13:55:34 by jgan              #+#    #+#             */
/*   Updated: 2016/01/03 13:55:39 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	button_press(int button, int y, int x, t_fol *f)
{
	if (button == 2)
		f->j_mod = (f->j_mod == 0 ? 1 : 0);
	if ((button == 4 && f->zoom < 8000000000000000) || button == 5)
	{
		if (button == 5)
			f->zoom /= 1.1;
		f->mid.x += f->curs.x * f->zoom * (button == 5 ? 0.1 : -0.1);
		f->mid.y += f->curs.y * f->zoom * (button == 5 ? 0.1 : -0.1);
		if (button == 4)
			f->zoom *= 1.1;
		f->i_max = f->type == 'b' || f->type == 'B' ? 50 : 100;
		init_it(f);
		init_ib(f);
	}
	return (x + y);
}

static void	print_param(t_fol *f)
{
	ft_printf("\n\n		---->PARAMS<----\n\n");
	ft_printf("   step : %.16f\n", f->step);
	ft_printf(" x|ymin : %.10f|", f->def_min.x);
	ft_printf("%.10f\n", f->def_min.y);
	ft_printf(" x|ymax : %.10f|", f->def_max.x);
	ft_printf("%.10f\n", f->def_max.y);
	ft_printf("   zoom : %ld\n", (long)f->zoom);
	ft_printf("    mid : %ld|", (long)f->mid.x);
	ft_printf("%ld\n", (long)f->mid.y);
	ft_printf("j_param : %.10f|", f->j_param.x);
	ft_printf("%.10f\n", f->j_param.y);
	ft_printf("  i_max : %d\n", f->i_max);
	ft_printf("  b_max : %d\n", f->b_max);
	ft_printf(" cursor : %.10f|", f->curs.x);
	ft_printf("%.10f\n", f->curs.y);
}

static int	mouse_hook(int y, int x, t_fol *f)
{
	f->curs.x = (x - f->mid.x) / f->zoom;
	f->curs.y = (y - f->mid.y) / f->zoom;
	return (0);
}

static int	fractol_core(t_fol *f)
{
	do_key(f);
	if (out_limits(f))
		exit(0);
	f->step = 1 / f->zoom;
	f->def_min.x = -f->mid.x / f->zoom;
	f->def_min.y = -f->mid.y / f->zoom;
	f->def_max.x = (WIN_H - f->mid.x) / f->zoom;
	f->def_max.y = (WIN_W - f->mid.y) / f->zoom;
	print_rules(f);
	print_param(f);
	if (f->type == 'j')
		julia(f);
	else if (f->type == 'b')
		buddha(f);
	else if (f->type == 'B')
		buddha2(f);
	else
		mandelbrot(f);
	mlx_put_image_to_window(f->mlx, f->win, f->im, 0, 0);
	return (1);
}

void		do_mlx(t_fol *f)
{
	mlx_hook(f->win, MotionNotify, PointerMotionMask, mouse_hook, f);
	mlx_hook(f->win, KeyPress, KeyPressMask, key_press, f);
	mlx_hook(f->win, KeyRelease, KeyReleaseMask, key_release, f);
	mlx_hook(f->win, ButtonPress, ButtonPressMask, button_press, f);
	mlx_loop_hook(f->mlx, fractol_core, f);
	mlx_loop(f->mlx);
}
