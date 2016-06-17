/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 11:53:09 by jgan              #+#    #+#             */
/*   Updated: 2015/11/21 12:05:14 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddc(char *s, char c, char lr)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	ret[0] = c;
	ret[1] = '\0';
	if (lr == 'l')
		ret = ft_strjoin(ret, s);
	else
		ret = ft_strjoin(s, ret);
	return (ret);
}
