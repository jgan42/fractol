/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 22:43:34 by jgan              #+#    #+#             */
/*   Updated: 2015/11/10 22:46:51 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		j;

	j = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[j + i] = src[i];
		++i;
	}
	dest[j + i] = '\0';
	return (dest);
}
