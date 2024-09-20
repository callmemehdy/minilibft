/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:36:07 by mel-akar          #+#    #+#             */
/*   Updated: 2024/09/20 10:03:54 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fds	*set_static(t_fds **fds)
{
	return (*fds);
}

t_fds	**get_static()
{
	static t_fds		*fds;
	return (&fds);
}

static void	merging(t_fds **list, int data)
{
	t_fds *node;

	node = malloc(sizeof(t_fds));
	if (!node)
		return ;
	node -> fd = data;
	node->next = *list;
	*list = node;
}

int	ft_open(char *path, int oflag, int p)	
{
	t_fds				**fds;
	int					fd;

	fds = get_static();
	fd = open(path, oflag, p);
	if (fd < 0)
		return (-1);
	merging(fds, fd);
	return (fd);
}

// void file()
// {
// 	system("lsof -c op");
// }

// int main()
// {
// 	atexit(file);
// 	char path[]= "File0";
// 	path[4]++; ft_open(path, O_CREAT | O_WRONLY, 0777);
// 	path[4]++; ft_open(path, O_CREAT | O_WRONLY, 0777);
// 	path[4]++; ft_open(path, O_CREAT | O_WRONLY, 0777);
// 	path[4]++; ft_open(path, O_CREAT | O_WRONLY, 0777);
// 	path[4]++; ft_open(path, O_CREAT | O_WRONLY, 0777);
// 	path[4]++; ft_open(path, O_CREAT | O_WRONLY, 0777);
// 	// close_all_fds();
// 	ft_close(3);
// 	ft_close(4);
// 	ft_close(5);
// 	ft_close(6);
// 	ft_close(7);
// 	ft_close(8);
// 	ft_close(9);
// 	for (t_fds *s = set_static(get_static()); s; s = s->next)
// 		printf("%d\n", s->fd);
// }
