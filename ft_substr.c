/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:25:36 by ael-amma          #+#    #+#             */
/*   Updated: 2024/08/19 10:54:37 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (!str)
		return (NULL);
	if (ft_strlen(str) < start)
		return (ft_strdup(""));
	if (ft_strlen(str + start) < len)
		len = ft_strlen(str + start);
	tmp = malloc(len + 1 * sizeof(char));
	if (tmp)
	{
		while (i < len)
		{
			tmp[i] = str[start + i];
			i++;
		}
		tmp[i] = 0;
	}
	return (tmp);
}
