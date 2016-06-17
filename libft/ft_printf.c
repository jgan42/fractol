/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 17:15:36 by jgan              #+#    #+#             */
/*   Updated: 2015/11/20 19:08:05 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_conv(char *s, va_list va, t_info *info)
{
	get_info(s, va, info);
	if (info->conv == 'd' || info->conv == 'D' || info->conv == 'i')
		print_int(va, info);
	else if (info->conv == 'c' || info->conv == 'C' || !is_conv(info->conv))
		print_char(va, info);
	else if (info->conv == 's' && info->lenmod != 'l')
		print_str(va, info);
	else if (info->conv == 's' || info->conv == 'S')
		print_wstr(va, info);
	else if (info->conv == 'f' || info->conv == 'F')
		print_float(va, info);
	else
		print_uint(va, info);
	free(info->flag);
}

static int	print_nomod(char *s, int *i)
{
	int		j;

	j = 0;
	while (s[j] && s[j] != '%')
		j++;
	write(1, s, j);
	*i += j;
	return (j);
}

static int	print_form(char *s, va_list va)
{
	t_info	*info;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			info = init_info();
			info->posn = i + 1;
			print_conv(s, va, info);
			ret += info->nb_print;
			i = info->posn + 1;
			free(info);
		}
		else
			ret += print_nomod(s + i, &i);
	}
	return (ret);
}

int			ft_printf(char *form, ...)
{
	va_list	va;
	int		i;

	if (!check_format(form))
		return (0);
	va_start(va, form);
	i = print_form(form, va);
	va_end(va);
	return (i);
}
