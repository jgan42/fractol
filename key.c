/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 20:22:58 by jgan              #+#    #+#             */
/*   Updated: 2016/02/07 20:23:02 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		do_key(t_fol *f)
{
	if (f->lr)
		(f->lr == 1 ? (f->mid.y -= 10) : (f->mid.y += 10));
	if (f->ud)
		(f->ud == 1 ? (f->mid.x -= 10) : (f->mid.x += 10));
	if (f->zoom_io)
	{
		if (f->zoom_io == 1)
			f->zoom /= 1.1;
		f->mid.x += f->curs.x * f->zoom * (f->zoom_io == 1 ? 0.1 : -0.1);
		f->mid.y += f->curs.y * f->zoom * (f->zoom_io == 1 ? 0.1 : -0.1);
		if (f->zoom_io == -1)
			f->zoom *= 1.1;
	}
	if (f->j_mod)
		f->j_param = f->curs;
	if (f->i_mod && f->i_max < 0xffffff)
		f->i_max += f->type == 'b' || f->type == 'B' ? 100 : 200;
	if (f->lr || f->ud || f->zoom_io || f->j_mod)
	{
		f->i_max = f->type == 'b' || f->type == 'B' ? 50 : 100;
		init_it(f);
		init_ib(f);
	}
}

static void	change_type(t_fol *f, int key)
{
	init_fractol(f);
	if (key == ONE)
		f->type = 'm';
	else if (key == TWO)
		f->type = 'j';
	else if (key == THREE)
		f->type = 'b';
	else if (key == FOUR)
		f->type = 'B';
}

int			key_press(int key, t_fol *f)
{
	if (key == LEFT || key == RIGHT)
		f->lr = (key == LEFT ? -1 : 1);
	if (key == UP || key == DOWN)
		f->ud = (key == UP ? -1 : 1);
	if ((key == PLUS && f->zoom < 8000000000000000) || key == MINUS)
		f->zoom_io = (key == PLUS ? -1 : 1);
	if ((key == C && ++(f->color) > 126) || (key == V && --(f->color) < 1))
		f->color = 0;
	if ((key == P || key == O) && init_it(f) && init_ib(f))
		f->power += (key == P ? 1 : -1);
	if (key == ONE || key == TWO || key == THREE || key == FOUR)
		change_type(f, key);
	if (key == ENTER)
		f->i_max += 10;
	if (key == SPACE)
		f->i_mod = (f->i_mod == 0 ? 1 : 0);
	if (key == NUM_0)
		init_fractol(f);
	if (key == ESC)
	{
		ft_putendl("fractol quit");
		exit(0);
	}
	return (0);
}

int			key_release(int key, t_fol *f)
{
	if (key == PLUS || key == MINUS)
		f->zoom_io = 0;
	else if (key == LEFT || key == RIGHT)
		f->lr = 0;
	else if (key == UP || key == DOWN)
		f->ud = 0;
	return (0);
}
