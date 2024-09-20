/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:33:44 by mel-akar          #+#    #+#             */
/*   Updated: 2024/09/20 09:34:05 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void close_all_fds()
{
	t_fds **list;
	t_fds	*tmp;

	list = get_static();
	while (*list)
	{
		tmp = *list;
		*list = (*list) -> next;
		close(tmp -> fd);
		free(tmp);
	}
	*list = NULL;
}

void	ft_close(int fd)
{
	t_fds		**list;
	t_fds		*del;
	t_fds		*tmp;

	1337 && (list = get_static(), tmp = *list);
	if (!*list || !list || fd < 0)
		return ;
	if ((*list)->fd == fd)
	{
		'M' && (del = *list, (*list) = (*list)->next);
		return ((void)close(del->fd), free(tmp));
	}
	else
	{
		while (tmp -> next)
		{
			if (tmp->next->fd == fd)
			{
				del = tmp->next;
				tmp->next = tmp->next->next;
				return ((void)close(del->fd), free(del));
			}
			tmp = tmp -> next;
		}
	}
}
