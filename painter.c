/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 14:01:45 by jgan              #+#    #+#             */
/*   Updated: 2015/12/24 14:01:54 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	color(t_fol *f, int i)
{
	double	ret;

	if (i < 3)
		return (0);
	ret = (double)i / f->i_max * 0x4000000;
	if (f->color > 0)
		ret += (f->color - 1) * 0xb111f;
	return ((int)ret);
}

void		put_pixel(t_fol *f, t_pt c, int color)
{
	int	*tmp;

	if (c.x >= WIN_H || c.y >= WIN_W || c.x < 0 || c.y < 0)
		return ;
	tmp = (int *)&f->imc[c.x * f->imlen + c.y * (f->bpp / 8)];
	*tmp = color;
}

t_pt		to_matrix(t_fol *f, t_cplx t)
{
	double	x;
	double	y;
	t_pt	p;

	x = t.x * f->zoom + f->mid.x;
	y = t.y * f->zoom + f->mid.y;
	p.x = (int)x;
	p.y = (int)y;
	return (p);
}

void		julia(t_fol *f)
{
	t_cplx	z;
	t_cplx	t;
	t_pt	i;

	t.x = f->def_min.x;
	while (t.x < f->def_max.x)
	{
		t.y = f->def_min.y;
		while (t.y < f->def_max.y)
		{
			i = to_matrix(f, t);
			if (i.x >= WIN_H || i.y >= WIN_W)
				return ;
			z = f->it[i.x][i.y].i == 0 ? t : f->it[i.x][i.y].z;
			while (mod2_c(z) < 4 && f->it[i.x][i.y].i < f->i_max)
			{
				z = sum_c(pow_c(z, f->power), f->j_param);
				++f->it[i.x][i.y].i;
			}
			f->it[i.x][i.y].z = z;
			put_pixel(f, i, color(f, f->it[i.x][i.y].i));
			t.y += f->step;
		}
		t.x += f->step;
	}
}

void		mandelbrot(t_fol *f)
{
	t_cplx	z;
	t_cplx	t;
	t_pt	i;

	t.x = f->def_min.x;
	while (t.x < f->def_max.x)
	{
		t.y = f->def_min.y;
		while (t.y < f->def_max.y)
		{
			i = to_matrix(f, t);
			if (i.x >= WIN_H || i.y >= WIN_W)
				return ;
			z = f->it[i.x][i.y].i == 0 ? f->j_param : f->it[i.x][i.y].z;
			while (mod2_c(z) < 4 && f->it[i.x][i.y].i < f->i_max)
			{
				z = sum_c(pow_c(z, f->power), t);
				++f->it[i.x][i.y].i;
			}
			f->it[i.x][i.y].z = z;
			put_pixel(f, i, color(f, f->it[i.x][i.y].i));
			t.y += f->step;
		}
		t.x += f->step;
	}
}
