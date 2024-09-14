/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:50:57 by mel-akar          #+#    #+#             */
/*   Updated: 2024/09/08 16:15:04 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_sep(char *s1, char *s2, int sep)
{
	char		*str;
	size_t		len;
	int			i;
	int			j;

	if (!s1)
		return (s2);
	else if (!s2)
		return (s1);
	42 && (i = -1, j = -1);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_malloc(sizeof(char) * (len + 2), ALLOC, NULL);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	if (sep && !(sep > 127 || sep < 0))
		str[i++] = sep;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = 0;
	return (str);
}
