/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:50:00 by jgan              #+#    #+#             */
/*   Updated: 2016/01/28 14:50:02 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putfloat(double n, t_info *info)
{
	unsigned long long	fill;
	long long			t;
	int					i;

	t = (long long)n;
	n -= t;
	i = -2;
	ft_putchar('.');
	++info->nb_print;
	if (!info->prec)
		info->prec = 6;
	while (++i < info->prec)
		n *= 10;
	if ((long long)n % 10 >= 5)
		n += 10;
	n /= 10;
	fill = (unsigned long long)n;
	t = nbrlen(fill, info);
	while (i > t)
	{
		ft_putchar('0');
		++info->nb_print;
		--i;
	}
	ft_putnbr_ull(fill, info);
}

void		print_float(va_list va, t_info *info)
{
	unsigned long long	ull;
	long long			ll;
	double				aff;

	aff = va_arg(va, double);
	ll = (long long)aff;
	ull = ll < 0 ? -ll : ll;
	if (ll < 0)
	{
		ft_putchar('-');
		++info->nb_print;
	}
	if (aff < 0)
		aff = -aff;
	if ((unsigned long long)(aff * 10) % 10 >= 5 && info->prec == -1)
		++ull;
	ft_putnbr_ull(ull, info);
	if (info->prec > -1)
		putfloat(aff, info);
}
