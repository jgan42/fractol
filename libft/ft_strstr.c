/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 23:40:51 by jgan              #+#    #+#             */
/*   Updated: 2015/11/10 23:42:24 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	if (!s1[0] && !s2[0])
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		while (s2[j] && s1[i + j] == s2[j])
			++j;
		if (!s2[j])
			return ((char *)s1 + i);
		++i;
	}
	return (NULL);
}
