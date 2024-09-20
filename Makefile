# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/17 17:16:16 by ael-amma          #+#    #+#              #
#    Updated: 2024/09/20 09:58:37 by mel-akar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS	=	ft_bzero.o ft_calloc.o ft_memset.o ft_split.o ft_strchr.o		\
			ft_strcmp.o ft_strdup.o ft_strlen.o ft_substr.o ft_strjoin_sep.o \
			garbage_collector.o ft_open.o ft_lentill.o ft_max_min.o ft_is.o	  \
			ft_close.o

NAME	=	libft.a

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	ar rcs $@ $(OBJS)

%.o		:	%.c libft.h
	cc -Wall -Wextra -Werror  -c $<

clean	:
	rm -rf $(OBJS)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all

.PHONY	:	clean