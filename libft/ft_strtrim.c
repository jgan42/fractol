/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 23:43:13 by jgan              #+#    #+#             */
/*   Updated: 2015/11/10 23:45:14 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		++i;
	if (!s[i])
		return ("");
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		--j;
	if (!(str = (char *)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	k = 0;
	while (k < j - i + 1)
	{
		str[k] = s[i + k];
		++k;
	}
	str[k] = '\0';
	return (str);
}
