
SHELL = /bin/zsh
NAME = ft_ls
CC = gcc

LIBRAIRIES_DIRECTORY = librairies/

ifeq ($(MUTE), yes)
	SILENT = -s
endif

OPTION_LIB = ft_optn_parse
LIBFT_LIB = Libft
LIBRAIRIES := $(OPTION_LIB) $(LIBFT_LIB)
LIBRAIRIES := $(addprefix $(LIBRAIRIES_DIRECTORY), $(LIBRAIRIES))
LIBRAIRIES_INCLUDES = $(OPTION_LIB)/includes $(LIBFT_LIB)/
vpath
libdir = $(filter $(join $(LIBRAIRIES_DIRECTORY), $(1)), $(LIBRAIRIES))

INCLUDES = includes/ $(addprefix librairies/, Libft/ ft_optn_parse)

CFLAGS = -g -Wall -Wextra -Werror $(addprefix -I, $(INCLUDES))

SRCS_DIR = sources/

SRCS = argparsing.c \
	   dominantopt.c \
	   main.c

OBJS = $(addprefix $(SRCS_DIR),$(SRCS:.c=.o))
DEPENDENCIES = $(OBJS:.o=.d)

LIBS_ARCHIVE_FILES = $(shell find $(CURDIR) -name "*.a")

all: get_lib $(NAME)

$(NAME): $(OBJS) $(LIBS_ARCHIVE_FILES)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS_ARCHIVE_FILES) -o $(NAME)

get_lib:
	#Compile libft.a
	make  $(SILENT) -C $(filter %$(LIBFT_LIB), $(LIBRAIRIES))
	#Compile liboptn.a
	make $(SILENT) -C $(call libdir, $(OPTION_LIB)) \
		LIBFT_INCLUDE=$(realpath $(call libdir, $(LIBFT_LIB)))



clean:
	$(foreach Lib, $(LIBRAIRIES), make -C $(Lib) $@ &&) true
	rm -f $(OBJS)

fclean: clean
	$(foreach Lib, $(LIBRAIRIES), make -C $(Lib) $@ &&) true
	rm -f $(NAME)

proper:fclean
	$(foreach Lib, $(LIBRAIRIES), make -C $(Lib) $@ &&) true
	rm -f $(DEPENDENCIES)


re: fclean all


%.d:%.c
		$(CC) -MM $(addprefix -I , $(INCLUDES)) $(filter %.c, $^) > $@
		PREREQUISITES=$$(cat $@ | cut -d : -f 2) && \
			echo "$(@:%.d=%.o) $@:$$PREREQUISITES" > $@

ifeq ($(filter $(MAKECMDGOALS), clean fclean proper),)
include $(DEPENDENCIES)
endif

.PHONY: all clean fclean re get_lib
#.SILENT: $(OBJS)
.DEFAULT_GOAL = all
