/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:45:26 by ael-amma          #+#    #+#             */
/*   Updated: 2024/09/06 18:01:08 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cword(const char *str, char c);

char	**ft_split(char const *str, char c)
{
	int		i;
	size_t	len;
	char	**words;

	i = 0;
	if (!str)
		return (NULL);
	words = ft_calloc(cword(str, c) + 1, sizeof(char *));
	if (!words)
		return (NULL);
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str)
		{
			(!ft_strchr(str, c)) && (len = ft_strlen(str));
			(ft_strchr(str, c)) && (len = ft_strchr(str, c) - str);
			words[i++] = ft_substr(str, 0, len);
			str += len;
		}
	}
	words[i] = NULL;
	return (words);
}

static int	cword(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

void	free2d(char **s)
{
	int		i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}