ifeq ($(MUTE), yes)
	SILENT = -s
endif

NAME = ft_ls
CC = gcc

LIBRAIRIES_DIRECTORY = librairies/
OPTION_LIB_FOLDER = ft_optn_parse
ABSOLUT_OPTION_FOLDER = $(addprefix $(LIBRAIRIES_DIRECTORY), $(OPTION_LIB_FOLDER))
LIBFT_FOLDER = Libft
ABSOLUT_LIBFT_FOLDER = $(addprefix $(LIBRAIRIES_DIRECTORY), $(LIBFT_FOLDER))
LIBRAIRIES := $(ABSOLUT_OPTION_FOLDER) $(ABSOLUT_LIBFT_FOLDER)
LIBRAIRIES_INCLUDES = $(join $(call libdir, $(OPTION_LIB_FOLDER))/, includes) \
					  $(ABSOLUT_LIBFT_FOLDER)
libdir = $(filter $(join $(LIBRAIRIES_DIRECTORY), $(1)), $(LIBRAIRIES))

INCLUDES = includes/ $(LIBRAIRIES_INCLUDES)

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
	$(info $(LIBRAIRIES) SEARCH : )
	make  $(SILENT) -C $(filter %$(LIBFT_FOLDER), $(LIBRAIRIES))
	#Compile liboptn.a
	make $(SILENT) -C $(call libdir, $(OPTION_LIB_FOLDER)) \
		LIBFT_INCLUDE=$(realpath $(call libdir, $(LIBFT_FOLDER)))

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
