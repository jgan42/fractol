/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 10:46:50 by jgan              #+#    #+#             */
/*   Updated: 2016/01/03 10:46:54 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			init_fractol(t_fol *f)
{
	f->zoom = WIN_H / 3;
	f->mid.x = f->type == 'j' ? WIN_H / 2 : 2 * WIN_H / 3;
	f->mid.y = WIN_W / 2;
	f->ud = 0;
	f->lr = 0;
	f->zoom_io = 0;
	f->color = 0;
	f->j_param.x = 0;
	f->j_param.y = 0;
	f->i_max = f->type == 'b' || f->type == 'B' ? 50 : 100;
	f->j_mod = 0;
	f->i_mod = 0;
	f->b_max = 0;
	f->b_max1 = 0;
	f->b_max2 = 0;
	f->i_min = 0;
	f->power = 2;
	init_it(f);
	init_ib(f);
	return (1);
}

int			init_it(t_fol *f)
{
	int	i;
	int	j;

	if (!f->it)
	{
		if (!(f->it = (t_it **)malloc(sizeof(t_it *) * WIN_H)))
			return (0);
		i = -1;
		while (++i < WIN_H)
			if (!(f->it[i] = (t_it *)malloc(sizeof(t_it) * WIN_W)))
				return (0);
	}
	i = -1;
	while (++i < WIN_H)
	{
		j = -1;
		while (++j < WIN_W)
		{
			f->it[i][j].z = f->j_param;
			f->it[i][j].i = 0;
		}
	}
	return (1);
}

static void	init_mlx(t_fol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_W, WIN_H, "Fractol");
	f->im = mlx_new_image(f->mlx, WIN_W, WIN_H);
	f->imc = mlx_get_data_addr(f->im, &f->bpp, &f->imlen, &f->endi);
}

void		print_rules(t_fol *f)
{
	ft_printf("\e[1;1H\e[2J		---->RULES<----\n\n");
	ft_printf("   Fractol type : (1/2/3/4)");
	if (f->type == 'j')
		ft_printf("Julia");
	else if (f->type == 'b')
		ft_printf("Buddha Simple");
	else if (f->type == 'B')
		ft_printf("Buddha Advanced");
	else
		ft_printf("Mandelbrot");
	ft_printf("\n   Base Formula : Z(n+1) = Z(n)^%d + C\n", f->power);
	ft_printf("            P/O : ++power/--power\n");
	ft_printf("         Arrows : translate image\n");
	ft_printf("Scroll or \"-/+\" : zoom\n");
	ft_printf("    Right click : Julia_params ");
	ft_printf(f->j_mod ? "ON\n" : "OFF\n");
	ft_printf("          SPACE : Auto_iteration ");
	ft_printf(f->i_mod ? "ON\n" : "OFF\n");
	ft_printf("            C/V : Color factor [%d]\n", f->color);
	ft_printf("      NUM_ENTER : iterate += 10\n");
	ft_printf("          NUM_0 : Reset fractol\n");
	ft_printf("            ESC : Fractol Exit\n");
}

int			main(int ac, char **av)
{
	t_fol	f;

	if (ac != 2)
	{
		ft_putendl("Please try : ./fractol Param");
		ft_putendl("Param : [julia || mandelbrot || buddha1 || Buddha2]");
		return (0);
	}
	f.type = av[1][0];
	f.it = NULL;
	f.ib = NULL;
	init_fractol(&f);
	init_mlx(&f);
	do_mlx(&f);
	return (0);
}
