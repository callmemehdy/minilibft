/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lentill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 01:28:30 by mel-akar          #+#    #+#             */
/*   Updated: 2024/09/05 01:31:03 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	lentill(char *s, char c)
{
	size_t	index;

	index = 0;
	while (s[index] && s[index] != c)
		index++;
	return (index);
}
