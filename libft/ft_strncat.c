/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 23:02:14 by jgan              #+#    #+#             */
/*   Updated: 2015/11/10 23:05:39 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(dest);
	i = 0;
	while (src[i] && i < n)
	{
		dest[j + i] = src[i];
		++i;
	}
	dest[j + i] = '\0';
	return (dest);
}
