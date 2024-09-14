/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:11:27 by ael-amma          #+#    #+#             */
/*   Updated: 2024/09/13 00:31:53 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

// ft_malloc macros
# define ALLOC 42
# define DEL 36
# define CLEAN 21


// ft_open macros
# define OPEN 24
# define CLOSE 12

typedef struct s_addr
{
	void			*addr;
	struct s_addr	*next;
}				t_addr;


typedef struct s_fds
{
	int				fd;
	struct s_fds	*next;
}				t_fds;

void	ft_bzero(void *buffer, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *str, char c);
char	*ft_strchr(const char *str, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// added by EL MEHDI ...
// ft_malloc use: allocMem as std malloc but give the option ALLOC and if u want to delete all allocatedMem give CLEAN option
// and if u wanna free a specific memory address uve mallocated u give its address as an option
char	*ft_strjoin_sep(char *s1, char *s2, int sep);
void	*ft_malloc(size_t size, int option, void *del);
int		ft_open(const char *path, int oflag, int perms, int mode);
size_t	lentill(char *s, char c);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	free2d(char **s);
int		ft_isdigit(char c);
int		ft_isalpha(char c);
int		ft_isupper(char c);
int		ft_islower(char c);
int		ft_isalphadigit(char c);

#endif
