/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:36:07 by mel-akar          #+#    #+#             */
/*   Updated: 2024/09/10 20:45:25 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void	merging(t_fds **list, int data)
// {
// 	t_fds *node;

// 	node = malloc(sizeof(t_fds));
// 	if (!node)
// 		return ;
// 	node -> fd = data;
// 	node->next = *list;
// 	*list = node;
// }
// #include <stdio.h>
// static void closing(t_fds **list)
// {
// 	t_fds	*tmp;

// 	while (*list)
// 	{
// 		write(1, "hello\n", 6);
// 		tmp = *list;
// 		*list = (*list) -> next;
// 		close(tmp -> fd);
// 		free(tmp);
// 	}
// 	*list = NULL;
// }

// int ft_open(const char *path, int oflag, int perms, int mode)
// {
// 	static t_fds	*fds;
// 	int				fd;

// 	fd = -1;
// 	if (mode == OPEN)
// 	{
// 		perms >= 0 && (fd = open(path, oflag, perms));
// 		perms == -1 && (fd = open(path, oflag));
// 		merging(&fds, fd);
// 	}
// 	else if (mode == CLOSE)
// 		closing(&fds);
// 	return (fd);
// }
