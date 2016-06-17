/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 01:39:22 by jgan              #+#    #+#             */
/*   Updated: 2015/11/19 23:09:55 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_w(int i, t_info *info)
{
	while (info->w_min > info->prec && info->w_min > i)
	{
		if (ft_strchr(info->flag, '0') && !ft_strchr(info->flag, '-'))
			ft_putchar('0');
		else
			ft_putchar(' ');
		(info->nb_print)++;
		(info->w_min)--;
	}
}

void		print_char(va_list va, t_info *info)
{
	int		c;

	if (!is_conv(info->conv))
		c = info->conv;
	else
		c = va_arg(va, wchar_t);
	if (!ft_strchr(info->flag, '-'))
		fill_w(wcharlen(c), info);
	if (c < 128 || (info->conv == 'c' && info->lenmod != 'l'))
	{
		ft_putchar(c);
		(info->nb_print)++;
	}
	else
		print_wchar(c, info);
	fill_w(wcharlen(c), info);
}

void		print_wchar(int c, t_info *info)
{
	char	*bin;
	char	*leaks;
	int		i;

	bin = get_unicode(c);
	i = 0;
	while (bin[i])
	{
		if (c < 128)
			ft_putchar(c);
		else
			ft_putchar(ft_atoi_base((leaks = ft_strndup(bin + i, 8)), "01"));
		if (c > 127)
			free(leaks);
		i += 8;
		(info->nb_print)++;
	}
	free(bin);
}

char		*get_unicode(int c)
{
	char	*bin;
	char	*code;
	int		i;
	int		j;

	bin = ft_itoa_base(c, "01");
	if (c < 2048)
		code = c < 128 ? ft_strdup("0xxxxxx") : ft_strdup("110xxxxx10xxxxxx");
	else if (c < 131072)
		code = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	else
		code = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	i = ft_strlen(code);
	j = ft_strlen(bin) - 1;
	while (--i > 0)
		if (code[i] == 'x')
		{
			if (j >= 0)
				code[i] = bin[j--];
			else
				code[i] = '0';
		}
	free(bin);
	return (code);
}
