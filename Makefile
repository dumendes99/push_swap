NAME = push_swap

CFLAGS = -Wall -Werror -Wextra 
CC = clang 

INCLUDE = ./include

LIBFT = libft.a
ARCHIVES = ./archives
LIBFT_PATH = ./libs/libft

LINK = -lft

SOURCES_PATH = ./sources
OBJECTS_PATH = ./objects

SOURCES_FILES = main.c \
				handler_input.c \
				utils.c \
				print_errors.c \
				swap.c \
				ft_chancheg.c \
				push.c \
				rotate.c \
				reverse_rotate.c \
				short_sort.c \
				big_sort.c \
				normalize.c \

SOURCES = $(addprefix $(SOURCES_PATH)/, $(SOURCES_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/, $(subst .c,.o,$(SOURCES_FILES)))

MAKE_EXTERNAL = make -C
SAFE_MAKEDIR = mkdir -p
REMOVE = rm -rf
COPY = cp -p

all: build_libft $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	$(CC) -g $(OBJECTS) -o $(NAME) -L $(ARCHIVES) -I $(INCLUDE) $(LINK)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c $(HEADER) 
	$(SAFE_MAKEDIR) $(OBJECTS_PATH)
	$(CC) $(CFLAGS) -g -I $(INCLUDE) -o $@ -c $<

build_libft:
	$(SAFE_MAKEDIR) $(ARCHIVES)
	$(MAKE_EXTERNAL) $(LIBFT_PATH)
	$(COPY) $(LIBFT_PATH)/$(LIBFT) $(ARCHIVES)

re: fclean all 

clean: 
	$(REMOVE) $(OBJECTS_PATH)
	$(MAKE_EXTERNAL) $(LIBFT_PATH) clean

fclean: clean
	$(REMOVE) $(NAME)
	$(MAKE_EXTERNAL) $(LIBFT_PATH) fclean
	$(REMOVE ARCHIVES)
