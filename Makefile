
CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g

SRCS = main.c parse.c philo_utils.c init.c moni.c

OBJS = $(SRCS:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)
	
re: clean all

.PHONY: all clean 