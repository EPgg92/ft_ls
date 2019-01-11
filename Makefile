
NAME = ft_ls
CC = gcc

INCLUDES = includes/

CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDES)

SRCS_DIR = sources/

SRCS = ft_argparsing.c
SRCS += ft_dominantopt.c
SRCS += ft_main.c

OBJS = $(addprefix $(SRCS_DIR),$(SRCS:.c=.o))

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
#.SILENT: $(OBJS)
