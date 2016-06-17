/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 14:27:40 by jgan              #+#    #+#             */
/*   Updated: 2016/01/21 14:27:46 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cplx	pow_c(t_cplx z, int p)
{
	double	t;

	while (p > 1)
	{
		t = z.x;
		z.x = (z.x * z.x - z.y * z.y);
		z.y = 2 * t * z.y;
		--p;
	}
	return (z);
}

t_cplx	sum_c(t_cplx z1, t_cplx z2)
{
	t_cplx	t;

	t.x = z1.x + z2.x;
	t.y = z1.y + z2.y;
	return (t);
}

double	mod2_c(t_cplx z)
{
	return (z.x * z.x + z.y * z.y);
}

int		out_limits(t_fol *f)
{
	if (f->mid.x > 6000000000000000 || f->mid.y > 6000000000000000
		|| f->mid.x < -6000000000000000 || f->mid.y < -6000000000000000
		|| f->zoom > 6000000000000000)
		return (1);
	return (0);
}
