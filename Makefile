ifeq ($(MUTE), yes)
	SILENT = -s
endif

NAME = ft_ls
CC = gcc

LIBRAIRIES_DIRECTORY = librairies/
LIBFT_FOLDER = Libft
ABSOLUT_LIBFT_FOLDER = $(addprefix $(LIBRAIRIES_DIRECTORY), $(LIBFT_FOLDER))
LIBRAIRIES := $(ABSOLUT_LIBFT_FOLDER)
LIBRAIRIES_INCLUDES = $(ABSOLUT_LIBFT_FOLDER)

libdir = $(filter $(join $(LIBRAIRIES_DIRECTORY), $(1)), $(LIBRAIRIES))

INCLUDES = includes/ $(LIBRAIRIES_INCLUDES)

CFLAGS = -g -Wall -Wextra -Werror $(addprefix -I, $(INCLUDES))

SRCS_DIR = sources/

SRCS = ls_parsing.c \
	   tfile_utils.c \
	   folder_reading.c \
	   sort_algorithm.c \
	   sort_functions.c \
	   maximum_setup.c \
	   argv_separator.c \

ifeq ($(filter $(MAKECMDGOALS), simon enzo),)
SRCS += main.c
endif

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

clean:
	$(foreach Lib, $(LIBRAIRIES), make -C $(Lib) $@ &&) true
	rm -f $(OBJS)

fclean: clean
	$(foreach Lib, $(LIBRAIRIES), make -C $(Lib) $@ &&) true
	rm -f $(NAME)

proper:fclean
	$(foreach Lib, $(LIBRAIRIES), make -C $(Lib) $@ &&) true
	rm -f $(DEPENDENCIES)

simon enzo: $(LIBS_ARCHIVE_FILES) | get_lib
enzo: $(OBJS) sources/enzo_main.o 
	$(CC) $(CFLAGS) $(filter-out get_lib, $^) $(LIBS_ARCHIVE_FILES) -o $(NAME)

simon: $(OBJS) sources/simon_main.o	
	$(CC) $(CFLAGS) $(filter-out get_lib, $^) $(LIBS_ARCHIVE_FILES) -o $(NAME)


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
