/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 22:09:31 by jgan              #+#    #+#             */
/*   Updated: 2015/11/10 22:10:14 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	if (!del)
		return ;
	tmp = *alst;
	while (tmp)
	{
		next = tmp->next;
		del(tmp->data);
		free(tmp);
		tmp = next;
	}
	*alst = NULL;
}
