# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/27 15:58:05 by simrossi     #+#   ##    ##    #+#        #
#    Updated: 2019/01/11 10:50:58 by simrossi    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES_PATH = ../Libft
INCLUDES = $(addprefix -I , $(INCLUDES_PATH))
CFLAGS += $(INCLUDES)

SRCS = flags_parse.c \
	   format_option_parser.c \
	   format_option_parser_utils.c \
	   is_verif.c \
	   option_category_setter.c \
	   t_prt_optn_utils.c \
	   number_field.c \
	   unicode_field.c \
	   string_field.c \
	   number_precision.c \
	   t_fcts_utils.c \
	   t_wfcts_utils.c \
	   function_builder.c \
	   std_integer_functions.c \
	   std_unsigned_functions.c \
	   std_base_functions.c \
	   std_base_utils.c \
	   std_string_functions.c \
	   std_unicode_functions.c \
	   std_other_functions.c \
	   string_displayers.c \
	   ft_printf.c \

OBJS = $(SRCS:.c=.o)

LIB = libft.a
LIBDIR = ../Libft/
LIB_PATH = $(addprefix $(LIBDIR), $(LIB))

all: $(NAME)

$(NAME): $(OBJS) $(LIB_PATH)
	make -C $(LIBDIR)
	ar -rc libftprintf_tmp.a $(OBJS)
	libtool -static -o $@ libftprintf_tmp.a $(LIB_PATH)
	rm libftprintf_tmp.a

$(LIB_PATH):
	make -C $(LIBDIR)

clean:
	rm -rf $(OBJS)
	make -C $(LIBDIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBDIR) fclean

re: fclean all

test: all
	gcc main.c -g $(NAME) $(LIB_PATH) $(INCLUDES)

.PHONY: all clean fclean re test
