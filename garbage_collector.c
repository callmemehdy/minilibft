/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:48:32 by mel-akar          #+#    #+#             */
/*   Updated: 2024/09/10 20:40:32 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// static size_t sizing(t_addr *list)
// {
// 	t_addr *tmp;
// 	size_t size;

// 	tmp = list;
// 	size = 0;
// 	while (tmp)
// 		42 && (size++, tmp = tmp -> next);
// 	return (size);
// }

static void	merging(t_addr **list, void *data)
{
	t_addr		*node;

	node = malloc(sizeof(node));
	if (!node)
		return ;
	node -> addr = data;
	node -> next = *list;
	*list = node;
}

static void	destroy_addr(t_addr *list)
{
	t_addr		*tmp;

	while (list)
	{
		tmp = list;
		list = list -> next;
		if (tmp && tmp->addr)
			free(tmp -> addr);
		free(tmp);
	}
}

static void	delete_node(t_addr **list, void *data)
{
	t_addr		*check;
	t_addr		*tmp;

	1337 && (check = *list, tmp = 0);
	if (!*list || !list || !data)
		return ;
	if ((*list)->addr == data && (*list)->addr)
	{
		tmp = *list;
		(*list) = (*list)->next;
		return (free(tmp->addr), free(tmp));
	}
	else
	{
		while (check -> next)
		{
			if (check -> next -> addr == data)
			{
				tmp = check -> next;
				check->next = check->next->next;
				if (tmp -> addr)
					free(tmp -> addr);
				return (free(tmp));
			}
			check = check -> next;
		}
	}
}

void	*ft_malloc(size_t size, int option, void *del)
{
	static t_addr	*list;
	void			*addr;

	addr = NULL;
	if (option == ALLOC)
	{
		addr = malloc(size);
		if (!addr)
			return (NULL);
		merging(&list, addr);
	}
	else if (option == CLEAN)
		destroy_addr(list);
	else if (option == DEL && del)
		delete_node(&list, del);
	return (addr);
}
