/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 15:19:36 by jgan              #+#    #+#             */
/*   Updated: 2015/11/20 18:21:09 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_w(long long int j, int i, t_info *info)
{
	if (j < 0 || ((info->conv == 'o' || info->conv == 'O')
		&& ft_strchr(info->flag, '#') && (j || info->prec)))
		(info->w_min)--;
	if (info->conv == 'p' || (ft_strchr(info->flag, '#') && (info->conv == 'x'
		|| info->conv == 'X')))
		info->w_min -= 2;
	if ((j < 0 || ((info->conv == 'o' || info->conv == 'O')
		&& ft_strchr(info->flag, '#') && j) || (info->conv == 'p'
		|| (ft_strchr(info->flag, '#') && (info->conv == 'x'
		|| info->conv == 'X')))) && !(info->prec) && (ft_strchr(info->flag, '0')
		&& !ft_strchr(info->flag, '-')))
		return ;
	while (info->w_min > info->prec && info->w_min > i)
	{
		if (ft_strchr(info->flag, '0') && !ft_strchr(info->flag, '-') && j >= 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		(info->nb_print)++;
		(info->w_min)--;
	}
}

static void	disp_uint(t_info *info, unsigned long long int aff)
{
	if ((info->conv == 'o' || info->conv == 'O') &&
		ft_strchr(info->flag, '#') && (aff || info->prec))
	{
		ft_putchar('0');
		(info->prec)--;
		(info->nb_print)++;
	}
	if ((((info->conv == 'o' || info->conv == 'O') && ft_strchr(info->flag, '#')
		&& aff) || (info->conv == 'p' || (ft_strchr(info->flag, '#')
			&& (info->conv == 'x' || info->conv == 'X'))))
				&& !(info->prec) && ft_strchr(info->flag, '0'))
		while (info->w_min > nbrlen(aff, info) && !ft_strchr(info->flag, '-'))
		{
			ft_putchar('0');
			(info->nb_print)++;
			(info->w_min)--;
		}
	fill_prec(aff, info);
	if (!(info->prec < 0 && aff == 0))
		ft_putnbr_ull(aff, info);
	fill_w(aff ? 1 : 0, nbrlen(aff, info), info);
}

void		print_uint(va_list va, t_info *info)
{
	unsigned long long int	aff;

	if (info->lenmod == 'L' || info->lenmod == 'z'
		|| info->lenmod == 'j' || info->conv == 'p')
		aff = va_arg(va, unsigned long long int);
	else if (info->conv == 'U' || info->conv == 'O' || info->lenmod == 'l')
		aff = va_arg(va, unsigned long int);
	else
		aff = va_arg(va, unsigned int);
	if (info->lenmod == 'H' && info->conv != 'U' && info->conv != 'O')
		aff = (unsigned char)aff;
	else if (info->lenmod == 'h' && info->conv != 'U' && info->conv != 'O')
		aff = (unsigned short int)aff;
	if (!aff && info->prec && info->w_min && !ft_strchr(info->flag, '0'))
		++info->w_min;
	if (!ft_strchr(info->flag, '-'))
		fill_w(aff ? 1 : 0, nbrlen(aff, info), info);
	if (info->conv == 'p' || (ft_strchr(info->flag, '#')
		&& (info->conv == 'x' || info->conv == 'X') && aff))
	{
		ft_putstr(info->conv == 'X' ? "0X" : "0x");
		info->nb_print += 2;
	}
	disp_uint(info, aff);
}
