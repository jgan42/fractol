/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 22:23:05 by jgan              #+#    #+#             */
/*   Updated: 2015/11/10 22:32:55 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*src1;
	char	*dest1;

	src1 = (char *)src;
	dest1 = (char *)dest;
	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		if ((unsigned char)src1[i] == (unsigned char)c)
			return ((char *)dest + i + 1);
		++i;
	}
	return (NULL);
}
