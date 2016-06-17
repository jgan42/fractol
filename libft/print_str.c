/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 01:43:12 by jgan              #+#    #+#             */
/*   Updated: 2015/11/20 18:09:00 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_w(int i, t_info *info)
{
	while (info->w_min > i)
	{
		if (info->w_min == info->prec && info->conv == 'S')
			return ;
		if (ft_strchr(info->flag, '0') && !ft_strchr(info->flag, '-'))
			ft_putchar('0');
		else
			ft_putchar(' ');
		(info->nb_print)++;
		(info->w_min)--;
	}
}

void		print_str(va_list va, t_info *info)
{
	char	*s;
	int		i;

	i = 0;
	if (!(s = va_arg(va, char *)))
		s = "(null)";
	if (!ft_strchr(info->flag, '-'))
	{
		if (info->prec == -1 && info->w_min)
			(info->w_min)--;
		if (!(info->prec && info->prec == -1 && !info->w_min))
			fill_w((info->prec && info->prec < (int)ft_strlen(s) ? info->prec :
				(info->prec = ft_strlen(s))), info);
	}
	while (s[i])
	{
		if (info->prec && i >= info->prec)
			break ;
		ft_putchar(s[i]);
		(info->nb_print)++;
		i++;
	}
	if (!(info->prec == -1 && !info->w_min))
		fill_w((info->prec && info->prec < (int)ft_strlen(s) ? info->prec :
			(int)ft_strlen(s)), info);
}

void		print_wstr(va_list va, t_info *info)
{
	wchar_t	*s;
	int		i;
	int		j;

	i = 0;
	s = va_arg(va, wchar_t *);
	if (!s)
	{
		write(1, "(null)", 6);
		info->nb_print += 6;
		return ;
	}
	if (!ft_strchr(info->flag, '-'))
		fill_w((info->prec ? wdisplen(s, info) : wstrlen(s)), info);
	j = (info->prec ? info->prec : wstrlen(s));
	while (s[i] && j >= wcharlen(s[i]))
	{
		print_wchar(s[i], info);
		j -= wcharlen(s[i]);
		i++;
	}
	fill_w((info->prec ? wdisplen(s, info) : wstrlen(s)), info);
}
