/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 17:29:25 by jgan              #+#    #+#             */
/*   Updated: 2015/11/20 18:08:30 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wcharlen(wchar_t c)
{
	char	*bin;
	int		i;
	int		j;

	bin = get_unicode(c);
	i = 0;
	j = 0;
	while (bin[i])
	{
		i += 8;
		j++;
	}
	free(bin);
	return (j);
}

int		wstrlen(wchar_t *s)
{
	char	*bin;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		bin = get_unicode(s[i]);
		while (bin[j])
		{
			j += 8;
			k++;
		}
		i++;
		free(bin);
	}
	return (k);
}

int		wdisplen(wchar_t *s, t_info *info)
{
	int		i;
	int		j;

	i = 0;
	j = info->prec;
	while (s[i] && j >= wcharlen(s[i]))
	{
		j -= wcharlen(s[i]);
		i++;
	}
	if (j && s[i] && info->prec != -1)
		info->prec -= j;
	return (i);
}

int		nbrlen(unsigned long long int n, t_info *info)
{
	char	*base;
	int		i;

	if (info->conv == 'o' || info->conv == 'O')
		base = "01234567";
	else if (info->conv == 'x' || info->conv == 'p')
		base = "0123456789abcdef";
	else if (info->conv == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789";
	i = 1;
	while (n >= (unsigned long long int)ft_strlen(base))
	{
		n /= (unsigned long long int)ft_strlen(base);
		i++;
	}
	return (i);
}
