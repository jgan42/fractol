/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 22:03:58 by jgan              #+#    #+#             */
/*   Updated: 2015/11/19 16:27:12 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(int n, const char *base)
{
	int		i;
	int		b;

	i = 1;
	b = (int)ft_strlen(base);
	while (n >= b)
	{
		n /= b;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(int n, const char *base)
{
	char	*s;
	int		len;
	int		i;
	int		b;

	len = nbrlen(n, base);
	b = (int)ft_strlen(base);
	if (!(s = ft_strnew(len)))
		return (NULL);
	i = 1;
	while (n > 0)
	{
		s[len - i] = n % b + '0';
		n /= b;
		i++;
	}
	return (s);
}
