/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 23:30:14 by jgan              #+#    #+#             */
/*   Updated: 2015/11/10 23:40:08 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_line(const char *s, const char *sep)
{
	int		i;
	int		nb;
	int		len;

	len = ft_strlen(sep);
	i = 0;
	nb = 0;
	while (s[i])
	{
		while (!ft_strncmp(s + i, sep, len))
			i += len;
		if (s[i])
			++nb;
		while (s[i] && ft_strncmp(s + i, sep, len))
			++i;
	}
	return (nb);
}

char		**ft_strsplitstr(const char *s, const char *sep)
{
	char	**tab;
	int		i;
	int		k;
	int		l;

	if (!(tab = (char **)malloc(sizeof(char *) * (nb_line(s, sep) + 1))))
		return (NULL);
	k = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && !ft_strncmp(s + i, sep, ft_strlen(sep)))
			i += ft_strlen(sep);
		l = i;
		while (s[i] && ft_strncmp(s + i, sep, ft_strlen(sep)))
			++i;
		if (i > l)
		{
			tab[k] = ft_strndup(s + l, i - l);
			++k;
		}
	}
	tab[k] = NULL;
	return (tab);
}
