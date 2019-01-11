NAME = ft_ls

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDES)

INCLUDES = includes


LIBS := liboptn.a libprintf.a libft.a
LIBS := $(addprefix libs/, $(LIBS))

SRCS != find srcs -name "*.c" 
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
