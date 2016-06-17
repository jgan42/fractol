/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 23:28:04 by jgan              #+#    #+#             */
/*   Updated: 2015/12/10 17:31:38 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbwords(char const *s, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] == c)
			++i;
		if (s[i])
			++nb;
		while (s[i] && s[i] != c)
			++i;
	}
	return (nb);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (!(tab = (char **)malloc(sizeof(char *) * (nbwords(s, c) + 1))))
		return (NULL);
	j = 0;
	k = 0;
	while (s[k])
	{
		while (s[k] == c)
			++k;
		i = k;
		while (s[k] && s[k] != c)
			++k;
		if (k > i)
		{
			tab[j] = ft_strndup(s + i, k - i);
			++j;
		}
	}
	tab[j] = NULL;
	return (tab);
}
