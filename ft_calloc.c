/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:50:56 by ael-amma          #+#    #+#             */
/*   Updated: 2024/08/18 14:36:52 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;

	buffer = (void *)malloc(count * size);
	if (buffer)
		ft_bzero(buffer, count * size);
	return (buffer);
}
