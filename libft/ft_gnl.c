/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 23:18:15 by jgan              #+#    #+#             */
/*   Updated: 2015/12/23 17:45:02 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	build_tmp(char ***tmp, int fd)
{
	char	**new;
	char	**new2;
	int		i;

	new = *tmp;
	i = 0;
	while (new && new[i])
		++i;
	if (new && i > fd)
		return (1);
	if (!(new2 = (char **)malloc(sizeof(char *) * (fd + 2))))
		return (0);
	i = -1;
	while (++i <= fd && new && new[i])
		new2[i] = new[i];
	while (i <= fd)
	{
		new2[i] = ft_strnew(0);
		++i;
	}
	new2[i] = NULL;
	free(new);
	*tmp = new2;
	return (1);
}

int			ft_gnl(int fd, char **line)
{
	static char	**tmp = NULL;
	static int	ret;
	char		buf[BUFF_SIZE + 1];
	char		*leaks;
	int			i;

	if (fd < 0 || !line || read(fd, buf, 0) || !build_tmp(&tmp, fd))
		return (-1);
	while (!ft_strchr(tmp[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		leaks = ft_strjoin(tmp[fd], buf);
		free(tmp[fd]);
		tmp[fd] = leaks;
	}
	i = 0;
	while (tmp[fd][i] && tmp[fd][i] != '\n')
		i++;
	*line = tmp[fd];
	tmp[fd] = ft_strdup(tmp[fd][i] ? tmp[fd] + i + 1 : tmp[fd] + i);
	(*line)[i] = '\0';
	return (ret || tmp[fd][0] ? 1 : 0);
}
