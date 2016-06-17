/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinttab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 22:40:07 by jgan              #+#    #+#             */
/*   Updated: 2015/11/10 22:41:19 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putinttab(int *tab, unsigned int len, const char *sep)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		ft_putnbr(tab[i]);
		ft_putstr(sep);
		++i;
	}
}
