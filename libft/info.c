/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 16:34:52 by jgan              #+#    #+#             */
/*   Updated: 2015/11/20 19:06:49 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_info	*init_info(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	info->nb_print = 0;
	info->posn = 0;
	info->w_min = 0;
	info->prec = 0;
	info->conv = '\0';
	info->flag = ft_strnew(0);
	info->lenmod = '\0';
	return (info);
}

void	get_info(char *s, va_list va, t_info *info)
{
	int		i;

	i = info->posn;
	while (is_flag(s[i]))
		i++;
	if (i > info->posn)
	{
		free(info->flag);
		info->flag = ft_strndup(s + info->posn, i - info->posn);
	}
	if (ft_isdigit(s[i]) || s[i] == '*')
		i = get_w_min(s, va, info, i);
	if (s[i] == '.')
		i = get_prec(s, va, info, i);
	if (is_lenmod(s[i]))
		i = get_lenmod(s, info, i);
	info->conv = s[i];
	info->posn = i;
}

int		get_prec(char *s, va_list va, t_info *info, int i)
{
	int		tmp;

	if (s[i + 1] == '*')
		tmp = va_arg(va, int);
	else
		tmp = ft_atoi(s + i + 1);
	info->prec = tmp < 1 ? -1 : tmp;
	++i;
	while (ft_isdigit(s[i]) || s[i] == '*' || s[i] == '-')
		++i;
	return (i);
}

int		get_w_min(char *s, va_list va, t_info *info, int i)
{
	char	*leaks;

	while (ft_isdigit(s[i]) || s[i] == '*')
	{
		if (ft_isdigit(s[i]) && ++i)
		{
			info->w_min = ft_atoi(s + i - 1);
			while (ft_isdigit(s[i]))
				++i;
		}
		if (s[i] == '*')
		{
			info->w_min = va_arg(va, int);
			i++;
		}
	}
	if (info->w_min < 0 && va)
	{
		leaks = ft_strjoin(info->flag, "-");
		free(info->flag);
		info->flag = leaks;
		info->w_min = -info->w_min;
	}
	return (i);
}

int		get_lenmod(char *s, t_info *info, int i)
{
	if ((s[i] == 'l' && s[i + 1] == 'l') || (s[i] == 'h' && s[i + 1] == 'h'))
	{
		info->lenmod = (s[i] == 'l' ? 'L' : 'H');
		i++;
	}
	else
		info->lenmod = s[i];
	i++;
	return (i);
}
