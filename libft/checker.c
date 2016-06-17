/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 18:29:14 by jgan              #+#    #+#             */
/*   Updated: 2015/12/23 12:22:31 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_conv(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D'
			|| c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U'
			|| c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == 'f'
			|| c == 'F')
		return (1);
	return (0);
}

int		is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (1);
	return (0);
}

int		is_lenmod(char c)
{
	if (c == 'l' || c == 'j' || c == 'z' || c == 'h')
		return (1);
	return (0);
}

int		check_format(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			++i;
			while (s[i] && is_flag(s[i]))
				++i;
			while (s[i] && (ft_isdigit(s[i]) || s[i] == '*'))
				i++;
			if (s[i] == '.' && s[++i])
				while (s[i] && (ft_isdigit(s[i]) || s[i] == '*' || s[i] == '-'))
					++i;
			if (is_lenmod(s[i]))
				i += ((s[i] == 'l' && s[i + 1] == 'l') ||
						(s[i] == 'h' && s[i + 1] == 'h') ? 2 : 1);
			if (!s[i])
				return (0);
		}
		i++;
	}
	return (1);
}
