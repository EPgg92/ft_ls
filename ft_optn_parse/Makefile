
#Variable definitions

NAME := liboptn.a

CC = gcc
#CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDES)
CFLAGS = -g  -I $(INCLUDES)

INCLUDES = includes

LIBS :=  libftprintf.a
LIBS := $(addprefix libs/, $(LIBS))

vpath *.c "srcs/t_optn"
VPATH = ./srcs/:./srcs/t_optn_utils/

SRCS = argv_check.c \
	   ft_argparse.c \
	   ft_isoptnname.c \
	   optn_routine.c\
	   print_optn.c\
	   t_args_nodes.c\
	   t_optn_freeing.c\
	   head_opt.c

OBJS = $(SRCS:.c=.o)
#Rules definitions

all : $(NAME)

$(NAME): $(OBJS)
	ar -rc $@ $^

#Cleaning rules

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

#Test rules

TEST_FILE := optparse.out
MAIN_TEST := main_test.c

test: $(TEST_FILE)

$(TEST_FILE): $(NAME) $(MAIN_TEST:.c=.o)
	$(CC) $(CFLAGS) -o $@ $(MAIN_TEST) $< $(LIBS)

rm_test:
	rm -rf $(TEST_FILE) $(MAIN_TEST:.c=.o) *.o

.PHONY: clean fclean re all test rm_test
