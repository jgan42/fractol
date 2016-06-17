/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddha2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 17:23:55 by jgan              #+#    #+#             */
/*   Updated: 2016/01/16 17:24:06 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	color(t_fol *f, t_it b)
{
	double	ret;
	double	n;
	double	max;
	double	t;

	n = b.z.x + b.z.y + b.i;
	max = f->b_max1 + f->b_max2 + f->b_max;
	if (n < 1000)
		ret = (int)((n / 1000) * 90) * 0x10000 + (int)((n / 1000) * 160);
	else if (n < 1800)
	{
		t = (n - 1000) / 1000;
		ret = 0x5a00a0 - (int)(t * 90) * 0x10000;
	}
	else
	{
		t = (n - 1800) / (max - 1800);
		ret = (int)(t * 255) * 0x10100 + (int)(t * 95) + 160;
	}
	if (!(f->color % 2))
		ret = (int)((double)b.z.x / f->b_max1 * 255) + (int)((double)b.z.y /
			f->b_max2 * 255) * 0x100 + (int)((double)b.i / f->b_max * 255) *
			0x10100;
	return ((int)ret);
}

static void	mini_step(t_fol *f, t_cplx z, int hit)
{
	t_pt	in;

	in = to_matrix(f, z);
	if (in.x >= 0 && in.x < WIN_H && in.y >= 0 && in.y < WIN_W)
	{
		if ((hit < 100) && ++f->it[in.x][in.y].z.x > f->b_max1)
			f->b_max1 = f->it[in.x][in.y].z.x;
		else if ((hit < 500) && ++f->it[in.x][in.y].z.y > f->b_max2)
			f->b_max2 = f->it[in.x][in.y].z.y;
		else if (++f->it[in.x][in.y].i > f->b_max)
			f->b_max = f->it[in.x][in.y].i;
	}
}

static void	one_case(t_fol *f, t_cplx *z, t_cplx t, t_cplx *b)
{
	while (mod2_c(*b) < 4 && f->hit < f->i_max)
	{
		*b = sum_c(pow_c(*b, f->power), t);
		++(f->hit);
	}
	if (f->hit < f->i_max && f->hit != f->ib[f->norm.x][f->norm.y].i)
	{
		*z = f->j_param;
		f->ib[f->norm.x][f->norm.y].i = 0;
		while (mod2_c(*z) < 4 && f->ib[f->norm.x][f->norm.y].i < f->i_max)
		{
			*z = sum_c(pow_c(*z, f->power), t);
			++f->ib[f->norm.x][f->norm.y].i;
			mini_step(f, *z, f->hit);
			z->y = -z->y;
			mini_step(f, *z, f->hit);
			z->y = -z->y;
		}
		f->ib[f->norm.x][f->norm.y].z = *z;
	}
	else
	{
		f->ib[f->norm.x][f->norm.y].z = *b;
		f->ib[f->norm.x][f->norm.y].i = f->hit;
	}
}

static void	calc_buddha(t_fol *f)
{
	t_cplx	z;
	t_cplx	t;
	t_cplx	b;

	t.x = -2.0;
	f->norm.x = -1;
	while (t.x < 1.0 && ++f->norm.x < 6000)
	{
		t.y = -1.5;
		f->norm.y = -1;
		while (t.y < 0 && ++f->norm.y < 3000)
		{
			b = f->ib[f->norm.x][f->norm.y].z;
			f->hit = f->ib[f->norm.x][f->norm.y].i;
			one_case(f, &z, t, &b);
			t.y += 0.0005;
		}
		t.x += 0.0005;
	}
	f->i_min = f->i_max;
}

void		buddha2(t_fol *f)
{
	t_pt	i;

	if (f->i_min != f->i_max)
		calc_buddha(f);
	i.x = -1;
	while (++i.x < WIN_H)
	{
		i.y = -1;
		while (++i.y < WIN_W)
			put_pixel(f, i, color(f, f->it[i.x][i.y]));
	}
}
