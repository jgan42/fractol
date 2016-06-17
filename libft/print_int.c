/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 15:19:36 by jgan              #+#    #+#             */
/*   Updated: 2015/11/20 18:20:25 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_w(long long int j, int i, t_info *info)
{
	if (j < 0 || (ft_strchr(info->flag, ' ') || ft_strchr(info->flag, '+')))
		(info->w_min)--;
	if ((j < 0 || (ft_strchr(info->flag, ' ') || ft_strchr(info->flag, '+')))
		&& !(info->prec) && (ft_strchr(info->flag, '0')
		&& !ft_strchr(info->flag, '-')))
		return ;
	while (info->w_min > info->prec && info->w_min > i)
	{
		if (ft_strchr(info->flag, '0') && !ft_strchr(info->flag, '-')
			&& j >= 0 && info->prec < 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		(info->nb_print)++;
		(info->w_min)--;
	}
}

void		disp_int(unsigned long long int aff, long long int i, t_info *info)
{
	if (!aff && info->prec && info->w_min && !ft_strchr(info->flag, '0'))
		++info->w_min;
	if (!ft_strchr(info->flag, '-'))
		fill_w(i, nbrlen(aff, info), info);
	if (i < 0 || ft_strchr(info->flag, '+') || ft_strchr(info->flag, ' '))
	{
		if (i < 0)
			ft_putchar('-');
		else
			ft_putchar(ft_strchr(info->flag, '+') ? '+' : ' ');
		(info->nb_print)++;
	}
	if ((i < 0 || ft_strchr(info->flag, '+') || ft_strchr(info->flag, ' '))
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
	fill_w(i, nbrlen(aff, info), info);
}

void		print_int(va_list va, t_info *info)
{
	unsigned long long int	aff;
	long long int			i;

	if (info->lenmod == 'L' || info->lenmod == 'z' || info->lenmod == 'j')
		i = va_arg(va, long long int);
	else if (info->conv == 'D' || info->lenmod == 'l')
		i = va_arg(va, long int);
	else
		i = va_arg(va, int);
	if (info->lenmod == 'H' && info->conv != 'D')
		i = (char)i;
	else if (info->lenmod == 'h' && info->conv != 'D')
		i = (short int)i;
	aff = (unsigned long long int)(i < 0 ? -i : i);
	disp_int(aff, i, info);
}

void		ft_putnbr_ull(unsigned long long int n, t_info *info)
{
	char	*base;

	if (info->conv == 'o' || info->conv == 'O')
		base = "01234567";
	else if (info->conv == 'x' || info->conv == 'p')
		base = "0123456789abcdef";
	else if (info->conv == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789";
	if (n >= ft_strlen(base))
	{
		ft_putnbr_ull(n / ft_strlen(base), info);
		ft_putnbr_ull(n % ft_strlen(base), info);
	}
	else if (n < ft_strlen(base))
	{
		ft_putchar(base[n]);
		(info->nb_print)++;
	}
}

void		fill_prec(unsigned long long int aff, t_info *info)
{
	int		i;

	i = info->prec;
	while (i > nbrlen(aff, info))
	{
		ft_putchar('0');
		(info->nb_print)++;
		i--;
	}
}
