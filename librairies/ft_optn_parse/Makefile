#Variable definitions

NAME := liboptn.a

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDES)

INCLUDES = includes
HEADER_DEPENDENCY := libft.h
HEADER_DEPENDENCY := $(addprefix $(INCLUDES)/, $(HEADER_DEPENDENCY))

LIBS :=  libft.a
LIBS := $(addprefix libs/, $(LIBS))

OPTN_UTILS = $(addprefix t_optn_utils/, optn_routine.c \
			 print_optn.c \
			 t_args_nodes.c \
			 t_optn_freeing.c )

SRCS = argv_check.c \
	   ft_argparse.c \
	   ft_isoptnname.c \
	   $(OPTN_UTILS)

SRCS := $(addprefix srcs/, $(SRCS))

OBJS = $(SRCS:.c=.o)
DEPENDENCIES = $(SRCS:%.c=%.d)

#####################
# Rules definitions #
#####################

all : $(HEADER_DEPENDENCY) $(NAME)

$(NAME): $(OBJS)
	ar -rc $@ $?

$(HEADER_DEPENDENCY):
	$(error File $@ is missing in $(INCLUDES) for $(NAME). Please add him in \
		the directory)

#Cleaning rules

clean:
	rm -f $(OBJS)

proper:clean
	rm -rf $(DEPENDENCIES)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE)

#Use $(CC) to generate dependecies + format rule to add have 
#rules like "%.o %.d: x.c y.h (etc.)"
%.d:%.c
	$(CC) -MM -I $(INCLUDES) $(filter %.c, $^) > $@
	PREREQUISITES=$$(cat $@ | cut -d : -f 2) && \
				  echo "$(@:%.d=%.o) $@:$$PREREQUISITES" > $@

#Avoid including .d files depending of called rule.
ifeq ($(filter $(MAKECMDGOALS), re fclean clean proper),)
include $(DEPENDENCIES)
endif

.PHONY: clean fclean re all proper
.DEFAULT_GOAL = all
