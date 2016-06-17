/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddha.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 17:23:55 by jgan              #+#    #+#             */
/*   Updated: 2016/01/16 17:24:06 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	color(t_fol *f, int b)
{
	double	ret;

	if (b > f->b_max * 0.8)
		return (0xffffff);
	if (b < 50)
		return (0);
	ret = (int)((double)b / f->b_max * 100000);
	if (f->color > 0)
		ret += (f->color - 1) * 0xb111f;
	return ((int)ret);
}

int			init_ib(t_fol *f)
{
	int	i;
	int	j;

	if (!f->ib)
	{
		if (!(f->ib = (t_it **)malloc(sizeof(t_it *) * 6000)))
			return (0);
		i = -1;
		while (++i < 6000)
			if (!(f->ib[i] = (t_it *)malloc(sizeof(t_it) * 3000)))
				return (0);
	}
	i = -1;
	while (++i < 6000)
	{
		j = -1;
		while (++j < 3000)
		{
			f->ib[i][j].i = 0;
			f->ib[i][j].z = f->j_param;
		}
	}
	f->i_min = 0;
	f->b_max = 0;
	return (1);
}

static void	one_case(t_fol *f, t_cplx t, t_cplx *z, t_pt i)
{
	t_pt	in;

	*z = sum_c(pow_c(*z, f->power), t);
	++f->ib[i.x][i.y].i;
	in = to_matrix(f, *z);
	if (in.x >= 0 && in.x < WIN_H && in.y >= 0 && in.y < WIN_W
		&& ++f->it[in.x][in.y].i > f->b_max)
		f->b_max = f->it[in.x][in.y].i;
	z->y = -z->y;
	in = to_matrix(f, *z);
	if (in.x >= 0 && in.x < WIN_H && in.y >= 0 && in.y < WIN_W
		&& ++f->it[in.x][in.y].i > f->b_max)
		f->b_max = f->it[in.x][in.y].i;
	z->y = -z->y;
}

static void	calc_buddha(t_fol *f)
{
	t_cplx	z;
	t_cplx	t;
	t_pt	i;

	t.x = -2.0;
	i.x = -1;
	while (t.x < 1.0 && ++i.x < 6000)
	{
		t.y = -1.5;
		i.y = -1;
		while (t.y < 0 && ++i.y < 3000)
		{
			z = f->ib[i.x][i.y].z;
			while (mod2_c(z) < 4 && f->ib[i.x][i.y].i < f->i_max)
				one_case(f, t, &z, i);
			f->ib[i.x][i.y].z = z;
			t.y += 0.0005;
		}
		t.x += 0.0005;
	}
	f->i_min = f->i_max;
}

void		buddha(t_fol *f)
{
	t_pt	i;

	if (f->i_min != f->i_max)
		calc_buddha(f);
	i.x = -1;
	while (++i.x < WIN_H)
	{
		i.y = -1;
		while (++i.y < WIN_W)
			put_pixel(f, i, color(f, f->it[i.x][i.y].i));
	}
}
