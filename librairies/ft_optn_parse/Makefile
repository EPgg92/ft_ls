#Variable definitions

NAME := liboptn.a

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror $(addprefix -I , $(INCLUDES))

INCLUDES = includes

HEADER_DEPENDENCY := libft.h
ifdef LIBFT_INCLUDE
	INCLUDES += $(LIBFT_INCLUDE)
	HEADER_DEPENDENCY := $(addprefix $(LIBFT_INCLUDE)/, $(HEADER_DEPENDENCY))
else
	HEADER_DEPENDENCY := $(addprefix $(INCLUDES)/, $(HEADER_DEPENDENCY))
endif

$(info $(HEADER_DEPENDENCY))

LIBS :=  libft.a
LIBS := $(addprefix libs/, $(LIBS))

OPTN_UTILS = $(addprefix t_optn_utils/, optn_routine.c \
			 print_optn.c \
			 t_args_nodes.c \
			 t_optn_freeing.c \
			 head_opt.c)

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
ifndef LIBFT_INCLUDE
	$(error File $@ is missing in $(INCLUDES) for $(NAME). Please add him in \
		the directory or to set it through the LIBFT_INCLUDE variable)
else
	HEADER_FILE=$(LIBFT_INCLUDE)/$(notdir $@) && \
			   	cp $$HEADER_FILE $(firstword $(INCLUDES))
endif

#Cleaning rules

clean:
	rm -f $(OBJS)

proper:clean
	rm -rf $(DEPENDENCIES)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE)

test:all
	gcc main_test.c $(NAME) ../Libft/libft.a -I ../Libft/ -I includes/

ifeq (1, $(words $(MAKEFILE_LIST)))
#Use $(CC) to generate dependecies + format rule to add have
#rules like "%.o %.d: x.c y.h (etc.)"
%.d:%.c
	$(CC) -MM $(addprefix -I, $(INCLUDES)) $(filter %.c, $^) > $@
	PREREQUISITES=$$(cat $@ | cut -d : -f 2) && \
				  echo "$(@:%.d=%.o) $@:$$PREREQUISITES" > $@
endif
#Avoid including .d files depending of called rule.
ifeq ($(filter $(MAKECMDGOALS), re fclean clean proper),)
include $(DEPENDENCIES)
endif

.PHONY: clean fclean re all proper
.DEFAULT_GOAL = all
