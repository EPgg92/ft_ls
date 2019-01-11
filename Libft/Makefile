# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 08:24:35 by simrossi     #+#   ##    ##    #+#        #
#    Updated: 2018/10/30 13:33:34 by simrossi    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDES)

INCLUDES = .

SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_fstrchr.c \
	   ft_fstrrchr.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_isspace.c \
	   ft_istrcmp.c \
	   ft_itoa.c \
	   ft_lltoa.c \
	   ft_itoabase.c \
	   ft_ltoabase.c \
	   ft_memalloc.c \
	   ft_memccpy.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memdel.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_pow.c \
	   ft_abs.c \
	   ft_putchar.c \
	   ft_putuchar.c \
	   ft_putchar_fd.c \
	   ft_putendl.c \
	   ft_putendl_fd.c \
	   ft_putnbr.c \
	   ft_putnbr_fd.c \
	   ft_putstr.c \
	   ft_putstr_fd.c \
	   ft_strcat.c \
	   ft_strchr.c \
	   ft_strpbrk.c \
	   ft_strclr.c \
	   ft_strcmp.c \
	   ft_strcpy.c \
	   ft_strdel.c \
	   ft_strclear.c \
	   ft_strdel_out.c \
	   ft_strdup.c \
	   ft_strequ.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_fstrjoin.c \
	   ft_strlcat.c \
	   ft_strlen.c \
	   ft_nbrlen.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strncat.c \
	   ft_strncmp.c \
	   ft_strncpy.c \
	   ft_strnequ.c \
	   ft_strnew.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strsplit.c \
	   ft_strstr.c \
	   ft_strsub.c \
	   ft_strtrim.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_wordcount.c \
	   ft_wordlen.c \
	   ft_start_with.c \
	   ft_strnlen.c \
	   ft_strswap.c \
	   ft_swap.c \
	   ft_strmove.c \
	   ft_strcspn.c \
	   ft_incharset.c \
	   ft_count.c \
	   ft_wstrlen.c \
	   ft_putwstr.c \
	   ft_putwchar.c \
	   determine_bytes.c \
	   str_byteslen.c \
	   ft_wstrdel.c \
	   ft_wstrcpy.c \
	   ft_wstrdup.c \
	   ft_readfile.c \
	   ft_rmdir.c \
	   get_next_line.c



OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar -rc $@ $^

lib:
	make -C libft

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
#.SILENT: $(OBJS)
