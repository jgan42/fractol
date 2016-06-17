/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 23:20:36 by jgan              #+#    #+#             */
/*   Updated: 2015/12/12 16:14:24 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *s1, const char *s2, size_t n)
{
	if (!(*s2))
		return ((char *)s1);
	if (!(*s1) || n == 0)
		return (NULL);
	if (*s1 == *s2)
	{
		if (ft_strnstr(s1 + 1, s2 + 1, n - 1) - 1 == s1)
			return ((char *)s1);
	}
	return (ft_strnstr(s1 + 1, s2, n - 1));
}
