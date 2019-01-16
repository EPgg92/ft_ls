# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: simrossi <simrossi@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 08:24:35 by simrossi     #+#   ##    ##    #+#        #
#    Updated: 2019/01/15 18:36:08 by epoggio     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a

#################### RULES IF MAKEFILE IS RUNNING ALONE ########################
ifeq (1, $(words MAKEFILE_LIST))
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDES)
INCLUDES = .

%.d:%.c
	$(CC) -MM -I $(INCLUDES) $(filter %.c, $^) > $@
	PREREQUISITES=$$(cat $@ | cut -d : -f 2) && \
				  echo "$(@:%.d=%.o) $@:$$PREREQUISITES" > $@
endif
################################################################################

SRCS_PRINTF = flags_parse.c \
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

SRCS_PRINTF := $(addprefix ft_printf/, $(SRCS_PRINTF))

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
	   free_str_array.c \
	   ft_strclear.c \
	   ft_strdel_out.c \
	   ft_strdup.c \
	   ft_duparray.c \
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
	   ft_move_strtab.c \
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
	   get_next_line.c \
	   $(SRCS_PRINTF)

DEPS_MAKEFILE = $(SRCS:%.c=%.d)


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar -rc $@ $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:fclean
	$(MAKE)

proper:fclean
	rm -rf $(DEPS_MAKEFILE)

ifeq ($(filter $(MAKECMDGOALS), clean fclean re proper),)
include $(DEPS_MAKEFILE)
endif
