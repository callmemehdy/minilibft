/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:11:27 by ael-amma          #+#    #+#             */
/*   Updated: 2024/09/20 09:57:24 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

// ft_malloc macros
# define ALLOC 42
# define DEL 36
# define CLEAN 21


// ft_open macros
typedef enum s_open
{
	OPEN,
	CLOSE_FD,
	CLOSE_ALL,
		
}			t_open;

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
size_t	lentill(char *s, char c);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	free2d(char **s);
int		ft_isdigit(char c);
int		ft_isalpha(char c);
int		ft_isupper(char c);
int		ft_islower(char c);
int		ft_isalphadigit(char c);

// some ft_open tools
t_fds	*set_static(t_fds **fds);
t_fds	**get_static();

/*
	ft_open: it opens a file and merge the returned fd with a static list of fds
	args: - path==>  the path of the file that u want to open
		  - oflag==> the flag or in other words the permissions that u'll have
		  		     when u get the file opened ex: O_CREAT, O_APPEND...
		  - p======> if u want to create a file , just put the perms that
				     give the owners of this file..., otherwise u put 0 into it.
*/
int		ft_open(char *path, int oflag, int p);
/*
	ft_close:
			  - it close the specified fd that u put in arguments if the ft_open
			    has already opened it, it searches for the fd from the static list
			    and make it a closed and remove it from the list...
*/
void	ft_close(int fd);
/*
	close_all_fds():
					 - its a void function that close all the fds that u have opened 
					   using ft_open function
*/
void	close_all_fds();
#endif
